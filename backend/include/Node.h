//
// Created by sujat on 12/7/24.
//

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

class Node {
public:
  vector<string> data; // Stores a row's values as strings
  Node *next;          // Pointer to the next node in the linked list

  Node(const vector<string> &rowData) : data(rowData), next(nullptr) {}
};

#endif // NODE_H
