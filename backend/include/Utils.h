//
// Created by sujat on 12/7/24.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "LinkedList.h"

using namespace std;

vector<string> split(const string& line, char delimiter);
vector<string> generateHeaders(const string& filename);
void parseCSV(const string& filename, LinkedList* l);

#endif // UTILS_H

