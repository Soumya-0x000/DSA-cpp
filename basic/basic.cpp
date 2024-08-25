#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    float a1, b1;

    cout << "Enter two numbers: " << endl;
    cin >> a1 >> b1;
    cout << "Enter two numbers: " << a1 + b1 << endl
         << endl;

    cout << "Enter three numbers: " << ends;
    cin >> n >> a >> b;

    cout << "1st number: " << n << endl
         << "2nd number: " << a << endl
         << "3rd one: " << b << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << "" << endl;

        for (int j = 0; j < i + 1; j++)
            cout << " *";

        cout << endl;
    }

    return 0;
}
