#include "TicketManager.h"
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <sqlite3.h>
namespace v
{
    TicketManager::TicketManager()
    {
    }
    bool TicketManager::generate(const MyMap &myData, const string &dbFilename)
    {
        sqlite3 *db = nullptr;
        char *errMsg = nullptr;
        int rc = sqlite3_open(dbFilename.c_str(), &db);
        if (rc != SQLITE_OK)
        {
            cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
            return false;
        }

        // Create table if it does not exist.
        string createTableSQL =
            "CREATE TABLE IF NOT EXISTS MyMapTable ("
            "mapKey TEXT, "
            "outerIndex INTEGER, "
            "col1 TEXT, "
            "col2 TEXT, "
            "col3 TEXT, "
            "col4 TEXT, "
            "col5 TEXT, "
            "col6 TEXT"
            ");";
        rc = sqlite3_exec(db, createTableSQL.c_str(), nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK)
        {
            cerr << "SQL error during table creation: " << errMsg << endl;
            sqlite3_free(errMsg);
            sqlite3_close(db);
            return false;
        }

        // Begin transaction for faster inserts.
        sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

        // For each map entry, insert each inner vector as a row.
        for (const auto &entry : myData)
        {
            const string &key = entry.first;
            const vector<vector<string>> &outerVec = entry.second;
            for (size_t i = 0; i < outerVec.size(); i++)
            {
                if (outerVec[i].size() != 6)
                {
                    cerr << "Error: inner vector for key '" << key
                         << "' at index " << i << " does not have 6 elements." << endl;
                    continue;
                }
                // Build the INSERT SQL.
                // (Note: For safety, in production code use prepared statements.)
                ostringstream oss;
                oss << "INSERT INTO MyMapTable (mapKey, outerIndex, col1, col2, col3, col4, col5, col6) VALUES ("
                    << "'" << key << "', "
                    << i << ", "
                    << "'" << outerVec[i][0] << "', "
                    << "'" << outerVec[i][1] << "', "
                    << "'" << outerVec[i][2] << "', "
                    << "'" << outerVec[i][3] << "', "
                    << "'" << outerVec[i][4] << "', "
                    << "'" << outerVec[i][5] << "');";
                string sqlInsert = oss.str();
                rc = sqlite3_exec(db, sqlInsert.c_str(), nullptr, nullptr, &errMsg);
                if (rc != SQLITE_OK)
                {
                    cerr << "SQL error during insert: " << errMsg << endl;
                    sqlite3_free(errMsg);
                }
            }
        }

        // End the transaction.
        sqlite3_exec(db, "END TRANSACTION;", nullptr, nullptr, nullptr);
        sqlite3_close(db);
        return true;
    }
    // Callback to build the MyMap structure.
int readMapCallback(void* data, int argc, char** argv, char** colNames) {
    MyMap* mapPtr = static_cast<MyMap*>(data);
    // Expecting columns: mapKey, outerIndex, col1, col2, col3, col4, col5, col6.
    if (argc < 8) return 1;
    (void)colNames;
    string key = argv[0] ? argv[0] : "";
    // We ignore outerIndex for reconstruction since we simply append rows in order.
    vector<string> inner;
    for (int i = 2; i < 8; ++i) {
        inner.push_back(argv[i] ? argv[i] : "");
    }
    (*mapPtr)[key].push_back(inner);
    return 0;
}

bool TicketManager::read(MyMap& myData, const string& dbFilename) {
    sqlite3* db = nullptr;
    char* errMsg = nullptr;
    int rc = sqlite3_open(dbFilename.c_str(), &db);
    if (rc != SQLITE_OK) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    
    string selectSQL = "SELECT mapKey, outerIndex, col1, col2, col3, col4, col5, col6 FROM MyMapTable ORDER BY mapKey, outerIndex;";
    rc = sqlite3_exec(db, selectSQL.c_str(), readMapCallback, &myData, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error during select: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }
    
    sqlite3_close(db);
    return true;
}


}