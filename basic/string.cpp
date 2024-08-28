#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

int main()
{
     string a, b, line;

     // by placing strings one after another
     cout << endl
          << "Enter a sentence: ";

     cin >> a >> b;
     cout << a << "\nsize of a: " << a.size() << endl << b << "\nsize of b: " << b.size() << endl
          << endl;

     // ignoring the last newline character
     cin.ignore(numeric_limits<streamsize>::max(), '\n');

     // using getline function
     cout << "Enter another sentence: ";
     getline(cin, line);
     cout << line << endl
          << endl;

     // using character pointer to store a sentence into char type variable
     const char* ch = "DSA isn't easy";
     cout << ch << endl << "size of ch: " << strlen(ch) << endl;

     // using char array to store a sentence
     char ch1[50];
     cout << "Write something: ";
     cin.getline(ch1, 100);

     cout << "Press any key to see output: ";
     getchar();
     cout << ch1;

     return 0;
}
