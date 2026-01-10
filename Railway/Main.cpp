#include "common.h"
#include "UserManagement.h"
#include "UserInterface.h"
#include "TicketManager.h"
#include "Vector.h" 
#include <unordered_map>

using namespace v;

typedef bool (UserInterface::*FuncPtr)(int &);
int main()
{
  UserManagement *userManager = new UserManagement();
  TicketManager *ticket = new TicketManager();
  UserInterface *ui = new UserInterface(userManager,ticket);
  Vector<FuncPtr> pages = {&UserInterface::entryPage, &UserInterface::login, &UserInterface::loggedIn, &UserInterface::createUser, &UserInterface::bookTickets, &UserInterface::viewTickets};
  clrscr();
  bool result = false;
  int page = 0;
  do
  {
    result = (ui->*pages[page])(page);
    clrscr();
    if (!result)
      printError(ui->error);
  } while (page != 100 && page >= 0 && page < 7);

  print("Thank you come again");
  delete (ui);
  delete (userManager);
  return 0;
}
