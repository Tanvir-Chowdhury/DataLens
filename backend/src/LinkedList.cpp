//
// Created by sujat on 12/7/24.
//

#include "LinkedList.h"
#include <iostream>
#include <stdexcept>
//#include <strings.h>
#include <vector>
//#include <windows.h>
using namespace std;

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
LinkedList::~LinkedList() {
  Node *current = head;
  while (current) {
    Node *nextNode = current->next;
    delete current;
    current = nextNode;
  }
}

// Insert a new node at the end of the list
void LinkedList::insert(const vector<string> &rowData) {
  Node *newNode = new Node(rowData);

  if (!head) { // List is empty
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  // cout << head<< endl;

  size++;
}

// Remove a node at a specific index
void LinkedList::remove(int index) {
  if (index < 0 || index >= size) {
    throw out_of_range("Index out of range.");
  }

  Node *current = head;
  Node *previous = nullptr;

  for (int i = 0; i < index; ++i) {
    previous = current;
    current = current->next;
  }

  if (!previous) { // Removing the head
    head = current->next;
  } else {
    previous->next = current->next;
  }

  if (!current->next) { // Removing the tail
    tail = previous;
  }

  delete current;
  size--;
}

// Search for a key in a specific column
Node *LinkedList::search(const string &key, int &columnIndex) {
  Node *current = head;

  while (current) {
    if (columnIndex < current->data.size() &&
        current->data[columnIndex] == key) {
      return current;
    }
    current = current->next;
  }

  return nullptr; // Key not found
}

// Display all nodes in the list
void LinkedList::display() const {
  Node *current = head;
  int i = 0;

  while (current != NULL && i != 10) {
    for (const string &value : current->data) {
      cout << value << " ";
    }
    cout << endl;
    current = current->next;
    i++;
  }
}
void LinkedList::returnColumn(int index, vector<string> *s) {
  Node *current = head;
  while (current != NULL) {
    cout << current->data[index] << endl;
    s->push_back(current->data[index]);
    current = current->next;
  }
}

void LinkedList::displayColumns() {

  for (const string &value : columns) {
    cout << value << " ";
  }
}

// Get the size of the list
int LinkedList::getSize() const { return size; }

// Get the head node
Node *LinkedList::getHead() const { return head; }
