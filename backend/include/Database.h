//
// Created by sujat on 12/7/24.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "LinkedList.h"
#include <string>
#include <unordered_map>

using namespace std;

class Database {
private:
  void loadData(
      const string
          &filename); // Loads data from a CSV file into a linked list,
                      // made private because it should not be used outside
                      // of loadDatabase(), if a new csv file is to be
                      // added to the database, the user should put it in $dir
public:
  unordered_map<string, LinkedList *> tables; // Maps filenames to linked lists
  Database();
  ~Database();

  void loadDatabase(const string &directoryPath);
  void saveDatabase(const string &directoryPath);
  void insert(const string &tableName, const vector<string> &rowData);
  void remove(const string &tableName, int index);
  // Node *search(int rowno);
  Node *search(const string &tableName, const string &key, int &columnIndex);
  void displayTable(const string &tableName);
  void displayAllTables();

  LinkedList *getTable(const string &tableName);
};

#endif // DATABASE_H
