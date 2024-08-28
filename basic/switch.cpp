#include<iostream>
using namespace std;

string getFirstName (string name) {
    if (name.length() > 1)
        return name.substr(0, name.find(' '));
    else
        return name;
}

enum Result {
    PASS,
    FAIL
};

int marks;
int main () {
    int marks;
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your marks: ";
    cin >> marks;

    Result result = (marks > 36) ? PASS : FAIL;

    switch (result) {
        case PASS :
            cout << getFirstName(name) << " you are passed with " << marks << " marks";
            break;

        case FAIL :
            cout << getFirstName(name) << " you are failed with " << marks << " marks";
            break;
            
        default:
            break;
    }
}
