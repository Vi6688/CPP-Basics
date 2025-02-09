#pragma once
#include "common.h"
#include "UserManagement.h"
#include "TicketManager.h"
namespace v
{
    class UserInterface
    {
    private:
        /* data */
        UserManagement *_userManager;
        string _username;

    public:
        UserInterface(UserManagement *userManager,TicketManager *ticket);
        ~UserInterface();
        string error;

        bool entryPage(int &page);
        bool login(int &page);
        bool loggedIn(int &page);
        bool createUser(int &page);
        bool bookTickets(int &page);
        bool viewTickets(int &page);
    };
   
}