#pragma once
#include "common.h"

namespace v
{
    class User
    {   
        private:
        string _user,_password,_email,_mobileNo;
        
        public:
        User(const string &name,const string &password,const string &email,const string &phoneNO):_user(name),_password(password),_email(email),_mobileNo(phoneNO)
        {
        }
        void setUserName(string &userName)
        {
            _user = userName;
        }
        void setPassword(string &password)
        {
            _password = password;
        }
        void setPhoneNo(string &no)
        {
            _mobileNo = no;
        }
        string getUsername()
        {
            return _user;
        }
        string getPassword()
        {
            return _password;
        }
        string getEmail()
        {
            return _email;
        }
        string getMobileNo()
        {
            return _mobileNo;
        }
    };
    
    class UserManagement
    {
    private:
        unordered_map<string , User*> _userList;
    public:
        UserManagement();
        // bool createUser(map<string,string> &userdetails);
        bool validateUsername(string &username);
        bool validatePassword(string &username, string &password);
        ~UserManagement();
    };
    
}