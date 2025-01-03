
#include "MemberList.h"

// Constructor: Initialize list and load members from CSV
MemberList::MemberList() : head(nullptr) { loadFromCSV(); }

// Destructor: Save members to CSV and free memory
MemberList::~MemberList() {
  saveToCSV();
  while (head) {
    Member *temp = head;
    head = head->next;
    delete temp;
  }
}

// Check if username already exists in the list
bool MemberList::usernameExists(const string &username) {
  Member *temp = head;
  while (temp) {
    if (temp->username == username)
      return true;
    temp = temp->next;
  }
  return false;
}

// Load members from CSV file
void MemberList::loadFromCSV() {
  ifstream file(csvFileName);
  if (!file.is_open())
    return;

  string line, name, username, password, type;
  while (getline(file, line)) {
    stringstream ss(line);
    getline(ss, name, ',');
    getline(ss, username, ',');
    getline(ss, password, ',');
    getline(ss, type, ',');

    Member *newMember = new Member(name, username, password, type);
    newMember->next = head;
    head = newMember;
  }
  file.close();
}

// Save members to CSV file
void MemberList::saveToCSV() {
  ofstream file(csvFileName);
  Member *temp = head;
  while (temp) {
    file << temp->name << "," << temp->username << "," << temp->password << ","
         << temp->memberType << "\n";
    temp = temp->next;
  }
  file.close();
}

// Register a new member
bool MemberList::registerMember(string name, string username, string password,
                                string type) {
  if (usernameExists(username)) {
    cout << "Error: Username already exists!\n";
    return false;
  }
  if (type != "user" && type != "admin") {
    cout << "Error: Invalid member type!\n";
    return false;
  }
  Member *newMember = new Member(name, username, password, type);
  newMember->next = head;
  head = newMember;
  saveToCSV();
  return true;
}

// Login functionality
string MemberList::loginMember(string username, string password) {
  Member *temp = head;
  while (temp) {
    if (temp->username == username && temp->password == password) {
      cout << "Login successful! Welcome, " << temp->name << " ("
           << temp->memberType << ").\n";
      return temp->memberType;
    }
    temp = temp->next;
  }
  return "";
}

// Delete a member (admin only, no password required)
bool MemberList::deleteMember(string username) {
  Member *curr = head, *prev = nullptr;

  while (curr) {
    if (curr->username == username) {
      if (prev)
        prev->next = curr->next;
      else
        head = curr->next;

      delete curr;
      saveToCSV();
      cout << "Member deleted successfully.\n";
      return true;
    }
    prev = curr;
    curr = curr->next;
  }
  cout << "Error: Member not found!\n";
  return false;
}

// Display all members (for debugging purposes)
void MemberList::displayMembers() {

  Member *temp = head;
  cout << "\nRegistered Members:\n";
  while (temp) {
    cout << temp->name << " | " << temp->username << " | " << temp->memberType
         << "\n";
    temp = temp->next;
  }
  cout << endl;
}
