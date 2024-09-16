#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 7, 1, 3, 9, 5, 4, 8, 6};
    int size;

    cout << endl
         << "Enter how many elements you want to insert: ";
    cin >> size;
    cout << endl;

    for (int i = 0; size--; ++i)
    {
        int num;
        cout << "Enter " << i + 1 << " number: ";
        cin >> num;
        arr.push_back(num);
    }
    cout << endl;
    
    for (auto &&i : arr)
        cout << "\t" << i << " ";

    // two dimesional array
    int row, col;
    cout << "\nEnter row number: ";
    cin >> row;
    cout << "Enter column number: ";
    cin >> col;
    cout << endl;

    vector<vector<int>> twoDarr(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cout << "Enter element for [" << i << "][" << j << "]: ";
            cin >> temp;
            twoDarr[i][j] = temp;
        }
        cout << endl;
    }

    cout << "\nTwo Dimensional Array: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << twoDarr[i][j] << " ";

        cout << endl;
    }
    cout << endl;

    return 0;
}
