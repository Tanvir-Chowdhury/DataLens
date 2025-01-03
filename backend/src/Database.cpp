//
// Created by sujat on 12/7/24.

#include "Database.h"
#include "LinkedList.h"
#include "Utils.h" // For split and parseCSV functions
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace std::filesystem;

// Constructor
Database::Database() {}

// Destructor to free dynamically allocated memory
Database::~Database() {
  for (auto &pair : tables) {
    delete pair.second;
  }
}

// Load data from a CSV file into a linked list
void Database::loadData(const string &filename) {
  // Generate headers and parse CSV file
  string tableName = path(filename).filename().string();

  // Generate headers and parse CSV file
  vector<string> headers = generateHeaders(filename);
  LinkedList *l = new LinkedList();
  l->columns = headers;
  parseCSV(filename, l);

  // Store the linked list in the map using the base filename
  tables[tableName] = l;
  cout << "Data loaded into table: " << tableName << endl;
}

void Database::loadDatabase(const string &directoryPath) {
  for (const auto &entry : filesystem::directory_iterator(directoryPath)) {
    if (entry.is_regular_file()) {
      string filePath = entry.path().string();
      loadData(filePath); // Reuse the existing loadData function
    }
  }
  cout << "Database loaded from directory: " << directoryPath << endl;
}
string escapeCSVField(const string &field) {
  if (field.find(',') != string::npos || field.find('"') != string::npos ||
      field.find('\n') != string::npos) {
    string escapedField = "\"";
    for (char c : field) {
      if (c == '"') {
        escapedField += "\"\""; // Escape quotes
      } else {
        escapedField += c;
      }
    }
    escapedField += "\"";
    return escapedField;
  }
  return field;
}

void Database::saveDatabase(const string &directoryPath) {
  for (const auto &pair : tables) {
    const string &tableName = pair.first; // Base filename
    LinkedList *table = pair.second;

    // Construct the full path to save the file
    string filePath = directoryPath + "/" + tableName;

    ofstream outFile(filePath);
    if (!outFile.is_open()) {
      cerr << "Error opening file for saving: " << filePath << endl;
      continue;
    }

    // Write the rows
    Node *current = table->getHead();
    while (current) {
      for (size_t i = 0; i < current->data.size(); ++i) {
        outFile << escapeCSVField(current->data[i]);
        if (i != current->data.size() - 1)
          outFile << ",";
      }
      outFile << endl;
      current = current->next;
    }

    outFile.close();
    cout << "Table saved: " << filePath << endl;
  }
}

// Helper function to escape fields for CSV format

// Insert a new row into a specific table
void Database::insert(const string &tableName, const vector<string> &rowData) {
  if (tables.find(tableName) == tables.end()) {
    throw invalid_argument("Table " + tableName + " does not exist.");
  }

  tables[tableName]->insert(rowData);
  cout << "Row inserted into " << tableName << " successfully." << endl;
}

// Remove a row from a specific table at a given index
void Database::remove(const string &tableName, int index) {
  if (tables.find(tableName) == tables.end()) {
    throw invalid_argument("Table " + tableName + " does not exist.");
  }

  tables[tableName]->remove(index);
  cout << "Row at index " << index << " removed from " << tableName
       << " successfully." << endl;
}

// Search for a key in a specific column of a table

// Display all rows in a specific table
void Database::displayTable(const string &tableName) {
  if (tables.find(tableName) == tables.end()) {
    throw invalid_argument("Table " + tableName + " does not exist.");
  }

  tables[tableName]->display();
}

// Display all tables in the database
void Database::displayAllTables() {
  for (const auto &pair : tables) {
    cout << "Table: " << pair.first << endl;
    pair.second->display();
    cout << endl;
  }
}

// Get a pointer to a table (linked list) by its name
LinkedList *Database::getTable(const string &tableName) {
  if (tables.find(tableName) == tables.end()) {
    return nullptr;
  }

  return tables[tableName];
}
Node *Database::search(const string &tableName, const string &key,
                       int &columnIndex) {
  if (tables.find(tableName) == tables.end()) {
    throw invalid_argument("Table " + tableName + " does not exist.");
  }

  return tables[tableName]->search(key, columnIndex);
}
