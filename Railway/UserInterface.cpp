#include "UserInterface.h"
#include "common.h"

namespace v
{
    UserInterface::UserInterface(UserManagement *userManager, [[maybe_unused]] TicketManager *ticket) : _userManager(userManager), _ticket(ticket)
    {
    }

    UserInterface::~UserInterface()
    {
    }

    bool UserInterface::entryPage([[maybe_unused]] int &page)
    {
        int option;
        v::print("::::Welcome to Railway Ticket Booking Platfom::::");
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
        String username, password;
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

        return true;
    }
    bool UserInterface::bookTickets([[maybe_unused]] int &page)
    {

        map<String, vector<vector<String>>> details;
        vector<String> passenger(6);
        println("Enter the departing station:");
        cin >> passenger[0];
        println("Enter the arriving station:");
        cin >> passenger[1];
        println("Enter the date(DD/MM/YYYY):");
        cin >> passenger[2];
        println("Enter the number of tickets:");
        cin >> passenger[3];
        int noOfTickets = std::stoi(passenger[3]);
        vector<vector<String>> passengers(noOfTickets);
        for (int i = 1; i <= noOfTickets; i++)
        {
            println("Enter  the name of the passenger" + to_String(i) + ":");
            cin >> passenger[4];
            println("Enter  the age of the passenger" + to_String(i) + ":");
            cin >> passenger[5];
            passengers[i - 1] = passenger;
        }
        details[_username] = passengers;
        if (_ticket->generate(details, _username))
            print("Tickets Booked succesfully");
        page = 2;
        return true;
    }
    bool UserInterface::viewTickets([[maybe_unused]] int &page)
    {
        map<String, vector<vector<String>>> details;

        _ticket->read(details, _username);
        vector<String> header = {"Departure", "Arrival", "Date", "tickets", "name", "age"};
        printRow(header);
        for (auto const &it : details)
        {
            vector<vector<String>> passengers = it.second;
            for (auto const &passenger : passengers)
            {
                printRow(passenger);
            }
        }

        print("1)print tickets");
        print("2)exit");
        int choice;
        println("Enter the choice:");
        cin >> choice;
        page = 2;
        return true;
    }
}