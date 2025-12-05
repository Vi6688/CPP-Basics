add_executable(Railway Main.cpp csvReader.cpp TicketManager.cpp UserManagement.cpp UserInterface.cpp)
target_include_directories(Railway PUBLIC ../Common)