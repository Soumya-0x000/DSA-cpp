#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, line;

    // by placing strings one after another
    cout << endl
         << "Enter a sentence: " ;

    cin >> a >> b;
    cout << a << " " << b << endl << endl;

    // ignoring the last newline character
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // using getline function
    cout << "Enter another sentence: ";
    getline(cin, line);
    cout << line << endl << endl;

    // using character pointer to store a sentence into char type variable
    const char *ch = "DSA isn't easy";
    cout << ch << endl;

    // using char array to store a sentence
    char ch1[50];
    cout << "Write something: ";
    cin.getline(ch1, 100);

    cout << "Press any key to see output: ";
    getchar();
    cout << ch1;

    return 0;
}
