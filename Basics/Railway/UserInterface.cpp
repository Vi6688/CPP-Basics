#include "UserInterface.h"
namespace v
{
    UserInterface::UserInterface(UserManagement *userManager) : _userManager(userManager)
    {
    }

    UserInterface::~UserInterface()
    {
    }

    bool UserInterface::entryPage([[maybe_unused]] int &page)
    {
        int option;
        print("::::Welcome to Railway Ticket Booking Platfom::::");
        print("1.)Login");
        print("2.)Create user");
        print("3.)Exit");
        println("Enter your choice :");
        cin >> option;
        if (option == 1)
            page = 1;
        else if (option == 2)
            page = 4;
        else
            page = 100;
        return true;
    }
    bool UserInterface::login([[maybe_unused]] int &page)
    {
        string username, password;
        print("____Welcome to login page____");
        println("Enter the username:");
        cin >> username;
        println("Enter the password:");
        cin >> password;
        if (!_userManager->validateUsername(username))
        {
            error = "Username Not Found.";
            page = 0;
            return false;
        }
        if (!_userManager->validatePassword(username, password))
        {
            error = "incorrect password";
            page = 0;
            return false;
        }
        page = 2;
        _username = username;
        return true;
    }
    bool UserInterface::loggedIn([[maybe_unused]] int &page)
    {
        int choice;
        print("Logged In successfully");
        print("1.)BookTickets");
        print("2.)ViewTickets");
        print("3.)Exit");
        println("Enter your choice :");
        cin >> choice;
        if (choice == 1)
            page = 4;
        else if (choice == 2)
            page = 5;
        else if (choice == 3)
            page = 0;
        else
        {
            page = 2;
            error = "Enter the valid choice";
        }
        return true;
    }
    bool UserInterface::createUser([[maybe_unused]] int &page)
    {
        string station1, station2, date, tickets;
        map<string, int> passengers;

        println("Enter the departing station:");
        cin >> station1;
        println("Enter the arriving station:");
        cin >> station2;
        println("Enter the date(DD/MM/YYYY):");
        cin >> date;
        println("Enter the number of tickets:");
        cin >> tickets;
        for (int i = 1; i <= tickets; i++)
        {
            string name, age;
            println("Enter  the name of the passenger" + string(i) + ":");
            cin >> name;
            println("Enter  the age of the passenger" + string(i) + ":");
            cin >> age;
            passengers[name] = age;
        }
        return true;
    }
    bool UserInterface::bookTickets([[maybe_unused]] int &page)
    {

        return true;
    }
    bool UserInterface::viewTickets([[maybe_unused]] int &page)
    {
        return true;
    }
}