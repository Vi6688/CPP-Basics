#pragma once
#include "common.h"
#include "String.h"

namespace v
{
using MyMap = std::map<String, std::vector<std::vector<String>>>;

class TicketManager
{
private:
    /* data */
public:
    TicketManager(/* args */);
    ~TicketManager();
    bool generate(const MyMap &myData, const String &dbFilename);
    bool read(MyMap &myData, const String &dbFilename);

};

}