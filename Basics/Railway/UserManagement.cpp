#include "UserManagement.h"
namespace v
{
    UserManagement::UserManagement()
    {
        vector<vector<String>> data;
        readCsv(data);
        for (const vector<String> &details : data)
        {
            User *user = new User(details[0], details[1], details[2], details[3]);
            _userList[details[0]] = user;
        }
    }

    // bool UserManagement::createUser(map<String, String> &userdetails)
    // {

    //     return true;
    // }
    bool UserManagement::validateUsername(String &username)
    {
        if (_userList.find(username) == _userList.end())
        {
            return false;
        }
        return true;
    }
    bool UserManagement::validatePassword(String &username, String &password)
    {
        return _userList[username]->getPassword() == password;
    }
    UserManagement::~UserManagement()
    {
    }

}