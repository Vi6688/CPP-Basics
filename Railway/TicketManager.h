#pragma once
#include "common.h"

namespace v
{
using MyMap = std::map<std::string, std::vector<std::vector<std::string>>>;

class TicketManager
{
private:
    /* data */
public:
    TicketManager(/* args */);
    ~TicketManager();
    bool generate(const MyMap &myData, const string &dbFilename);
    bool read(MyMap &myData, const string &dbFilename);

};

}