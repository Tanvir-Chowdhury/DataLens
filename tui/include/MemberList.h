

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
//using namespace std::byte;

// Structure to hold member details
struct Member {
    string name;
    string username;
    string password;
    string memberType;
    Member* next;

    Member(string n, string u, string p, string t)
        : name(n), username(u), password(p), memberType(t), next(nullptr) {}
};

// Class to manage the list of members
class MemberList {
private:
    Member* head; // Linked list head
    const string csvFileName = "members.csv";

    void loadFromCSV();
    void saveToCSV();
    bool usernameExists(const string& username);

public:
    MemberList();
    ~MemberList();

    bool registerMember(string name, string username, string password, string type);
    string loginMember(string username, string password);
    bool deleteMember(string username);
    void displayMembers();
};

