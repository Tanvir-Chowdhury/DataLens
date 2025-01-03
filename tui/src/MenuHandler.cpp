

#include "MenuHandler.h"
#include "Database.h"
//#include <cstdlib>
#include <qapplication.h>
//#include <unistd.h>

#include <limits>

using namespace std;
MenuHandler::MenuHandler(Database *d, string dir) {
  db = d;
  directory = dir;
}

void MenuHandler::start() {
  MemberList memberList;

  while (true) {
    clearScreen();
    cout << "\n===== Welcome =====\n";
    cout << "1. Login\n2. Register\n3. Exit\nEnter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      loginMember(memberList);
      break;
    case 2:
      registerMember(memberList);
      break;
    case 3:
      cout << "Goodbye!\n";
      exit(0);
    default:
      cout << "Invalid choice! Try again.\n";
      break;
    }
  }
}
void MenuHandler::loginMember(MemberList &memberList) {
  string username, password;

  clearScreen();
  cout << "Login Portal:\n";
  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;

  string memberType = memberList.loginMember(username, password);
  if (memberType == "admin") {
    system("pause");
    adminMenu(memberList);
  } else if (memberType == "user") {
    system("pause");
    userMenu();
  } else {
    cout << "Invalid credentials. Please try again.\n";
    system("pause");
  }
}

void MenuHandler::registerMember(MemberList &memberList) {
  string name, username, password, type;

  clearScreen();
  cout << "Register New Member:\n";
  cout << "Name: ";
  cin >> name;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;
  cout << "Member Type (user/admin): ";
  cin >> type;

  if (memberList.registerMember(name, username, password, type)) {
    cout << "Registration successful!\n";
  } else {
    cout << "Registration failed. Try again.\n";
  }
  system("pause");
}

void MenuHandler::adminMenu(MemberList &memberList) {
  while (true) {
    clearScreen();
    cout << "\n===== Admin Menu =====\n";
    cout << "1. Display Members\n2. Delete Member\n";
    cout << "3. Add Data to CSV" << endl;
    cout << "4. Delete Data" << endl;
    cout << "5. Show Data" << endl;
    cout << "6. Search Data" << endl;
    cout << "7. Logout" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      memberList.displayMembers();
        cout << "Press Enter to continue..."<<endl;
        cin.ignore();
        cin.get(); 
      break;
    case 2: {
      string username;
      cout << "Enter Username to Delete: ";
      cin >> username;
      memberList.deleteMember(username);
      break;
    }
    case 3:
      cout << "Adding Data to CSV..." << endl;
      break;
    case 4:
      DeleteData();
      break;
    case 5:
      // showDataSubmenu();
      ShowData();
      break;
    case 6:
      searchDataSubmenu();
      break;
    case 7:
      cout << "Logging out...\n";
      system("pause");
      return;
    default:
      cout << "Invalid choice! Try again." << endl;
    }
    system("pause");
  }
}
void MenuHandler::DeleteData() {
  while (true) {
    clearScreen();
    cout << "\n===== Choose a CSV file =====\n";
    cout << "1. athletes.csv" << endl;
    cout << "2. coaches.csv" << endl;
    cout << "3. events.csv" << endl;
    cout << "4. medallists.csv" << endl;
    cout << "5. medals.csv" << endl;
    cout << "6. medals_total.csv" << endl;
    cout << "7. nocs.csv" << endl;
    cout << "8. teams.csv" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";

    int ch;
    int ind;
    cin >> ch;

    // Check the user's choice
    switch (ch) {
    case 1:
      cout << "You chose athletes.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("athletes.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();
      break;
    case 2:
      cout << "You chose coaches.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("coaches.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 3:
      cout << "You chose events.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("events.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 4:
      cout << "You chose medallists.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("medallists.csv")->remove(ind - 1);
      db->saveDatabase(directory);

      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();
      break;
    case 5:
      cout << "You chose medals.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("medals.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 6:
      cout << "You chose medals_total.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("medals_total.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 7:
      cout << "You chose nocs.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("nocs.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 8:
      cout << "You chose teams.csv" << endl;
      cout << "Choose the index of the row to be deleted: " << endl;
      cin >> ind;
      db->getTable("teams.csv")->remove(ind - 1);
      db->saveDatabase(directory);
      clearScreen();
      cout << "The row is deleted" << endl;
      cout << "Press Enter to continue..." << endl;
      cin.ignore();
      cin.get();

      break;
    case 9:
      cout << "Going Back" << endl;
      return;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
void MenuHandler::ShowData() {
  while (true) {
    clearScreen();
    cout << "\n===== Choose a CSV file =====\n";
    cout << "1. athletes.csv" << endl;
    cout << "2. coaches.csv" << endl;
    cout << "3. events.csv" << endl;
    cout << "4. medallists.csv" << endl;
    cout << "5. medals.csv" << endl;
    cout << "6. medals_total.csv" << endl;
    cout << "7. nocs.csv" << endl;
    cout << "8. teams.csv" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";

    int ch;
    int index;
    cin >> ch;

    // Check the user's choice
    switch (ch) {
    case 1:
      viewTable("athletes.csv");
      break;
    case 2:
      viewTable("coaches.csv");

      break;
    case 3:
      viewTable("events.csv");
      break;
    case 4:
      viewTable("medallists.csv");
      break;
    case 5:
      viewTable("medals.csv");

      break;
    case 6:
      viewTable("medals_total.csv");

      break;
    case 7:
      viewTable("nocs.csv");

      break;
    case 8:
      viewTable("teams.csv");
      break;
    case 9:
      cout << "Going Back" << endl;
      return;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}
void MenuHandler::viewTable(string s) {
  int argc = 0;
  char *argv[] = {nullptr};
  QApplication app(argc, argv);

  QString csvFileName = QString::fromStdString(s);

  TableViewer viewer(csvFileName, directory);
  viewer.show();
  app.exec();
}

void MenuHandler::userMenu() {
  while (true) {
    clearScreen();
    cout << "\n===== User Menu =====\n";
    cout << "1. Show Data\n2. Search Data\n3. Logout\nEnter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:

      ShowData();
      break;
    case 2:
      searchDataSubmenu();
      break;
    case 3:
      cout << "Logging out...\n";
      system("pause");
      return;
    default:
      cout << "Invalid choice! Try again." << endl;
    }
    system("pause");
  }
}
void MenuHandler::searchTable(string s) {
  int argc = 0;

  char *argv[] = {nullptr};
  QApplication app(argc, argv);

  QString csvFileName = QString::fromStdString(s);

  searchInCSV(csvFileName, directory);
}

void MenuHandler::searchDataSubmenu() {
  while (true) {
    clearScreen();
    cout << "\n===== Search Data =====" << endl;
    cout << "1. Athletes Data" << endl;
    cout << "2. Coaches Data" << endl;
    cout << "3. Teams Data" << endl;
    cout << "4. Back" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      searchTable("athletes.csv");
      break;
    case 2:
      searchTable("coaches.csv");

      break;
    case 3:
      searchTable("teams.csv");
      break;
    case 4:
      cout << "Returning to the previous menu...\n";
      return;
    default:
      cout << "Invalid choice! Please try again." << endl;
    }
    system("pause");
  }
}

void MenuHandler::clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
