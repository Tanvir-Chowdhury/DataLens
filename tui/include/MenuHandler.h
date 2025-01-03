

#include "Database.h"
#include "MemberList.h"
#include "QApplication"
#include "TableViewer.h"
#include <QString>
//#include <cstdlib>
#include "searchInCSV.h"
#include <iostream>
#include <qapplication.h>
#include <string>
#include <windows.h>

class MenuHandler {
public:
  Database *db;
  string directory;
  MenuHandler(Database *d, string dir);
  void start();

private:
  void registerMember(MemberList &memberList);
  void loginMember(MemberList &memberList);
  void adminMenu(MemberList &memberList);
  void userMenu();
  void showDataSubmenu();
  void searchDataSubmenu();
  void searchAthletesData();
  void searchCoachesData();
  void searchTeamsData();
  void clearScreen();
  void DeleteData();
  void ShowData();
  void viewTable(string s);
  void searchTable(string s);
};
