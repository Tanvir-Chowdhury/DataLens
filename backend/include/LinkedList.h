//
// Created by sujat on 12/7/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <vector>

using namespace std;

class LinkedList {
private:
  Node *head;
  Node *tail;
  int size;

public:
  vector<string> columns;
  LinkedList();
  ~LinkedList();

  void insert(const vector<string> &rowData);
  void remove(int index); // Removes node at specified index
  Node *search(const string &key, int &columnIndex);
  void display() const; // Prints all nodes
  void displayColumns();
  void returnColumn(int index, vector<string> *s);

  int getSize() const;
  Node *getHead() const;
};

#endif // LINKEDLIST_H
