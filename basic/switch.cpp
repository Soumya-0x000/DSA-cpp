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

const int passsmarks = 36;

int main () {
    int marks;
    string name;

    cout << "Enter your name: ";
    getline(cin, name);
    string firstName = getFirstName(name);

    cout << "Enter your marks: ";
    cin >> marks;
    cout << endl;

    Result result = (marks > passsmarks) ? PASS : FAIL;

    switch (result) {
        case PASS :
            cout << firstName << ", you are passed with " << marks << " marks";
            break;

        case FAIL :
            cout << firstName << ", you are failed with " << marks << " marks" << " and need more " << (passsmarks - marks) << " marks to get promoted.";
            break;

        default :
            cout << "Invalid result";
            break;
    }

    return 0;
}
