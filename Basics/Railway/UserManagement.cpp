#include "UserManagement.h"
namespace v
{
    UserManagement::UserManagement()
    {
        vector<vector<string>> data;
        readCsv(data);
        for (const vector<string> &details : data)
        {
            User *user = new User(details[0], details[1], details[2], details[3]);
            _userList[details[0]] = user;
        }
    }

    // bool UserManagement::createUser(map<string, string> &userdetails)
    // {

    //     return true;
    // }
    bool UserManagement::validateUsername(string &username)
    {
        if (_userList.find(username) == _userList.end())
        {
            return false;
        }
        return true;
    }
    bool UserManagement::validatePassword(string &username, string &password)
    {
        return _userList[username]->getPassword() == password;
    }
    UserManagement::~UserManagement()
    {
    }

}