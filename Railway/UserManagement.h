#pragma once
#include "String.h"
#include "common.h"

namespace v
{
    class User
    {   
        private:
        String _user,_password,_email,_mobileNo;
        
        public:
        User(const String &name,const String &password,const String &email,const String &phoneNO):_user(name),_password(password),_email(email),_mobileNo(phoneNO)
        {
        }
        void setUserName(String &userName)
        {
            _user = userName;
        }
        void setPassword(String &password)
        {
            _password = password;
        }
        void setPhoneNo(String &no)
        {
            _mobileNo = no;
        }
        String getUsername()
        {
            return _user;
        }
        String getPassword()
        {
            return _password;
        }
        String getEmail()
        {
            return _email;
        }
        String getMobileNo()
        {
            return _mobileNo;
        }
    };
    
    class UserManagement
    {
    private:
        unordered_map<String , User*> _userList;
    public:
        UserManagement();
        // bool createUser(map<String,String> &userdetails);
        bool validateUsername(String &username);
        bool validatePassword(String &username, String &password);
        ~UserManagement();
    };
    
}