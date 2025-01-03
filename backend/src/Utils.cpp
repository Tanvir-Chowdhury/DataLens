//
// Created by sujat on 12/7/24.
//

#include "Utils.h"

//#include "Utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "LinkedList.h"

using namespace std;

// Splits a string into a vector of strings using a given delimiter

vector<string> split(const string& line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> generateHeaders(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    // Step 1: Read the header line
    string header_line;
    if (!getline(file, header_line)) {
        throw runtime_error("File is empty or missing a header line: " + filename);
    }

    // Split the header line into column names
    vector<string> headers = split(header_line, ',');

    /*cout << "Headers: ";
    for (const auto& header : headers) {
        cout << header << " ";
    }
    cout << endl;*/

    return headers;


}




void parseCSV(const string& filename, LinkedList* l) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        bool insideQuotes = false;
        string currentCell;

        while (ss.good()) {
            char c = ss.get();
            if (c == '"') {
                insideQuotes = !insideQuotes; // Toggle the inside-quote state
            } else if (c == ',' && !insideQuotes) {
                // End of cell
                row.push_back(currentCell);
                currentCell.clear();
            } else if (c != EOF) {
                currentCell += c;
            }
        }
        // Add the last cell
        if (!currentCell.empty()) {
            row.push_back(currentCell);
        }

        // Add the row to the linked list
        l->insert(row);
    }

    file.close();
}

