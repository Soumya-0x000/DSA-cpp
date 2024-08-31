#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 1, 3, 9, 5, 4, 8, 6};
    int size;

    cout << "Enter how many elements you want to insert: ";
    cin >> size;

    for (int _; size--; ) {
        int num;
        cout << "Enter number: " << "\t";
        cin >> num;
        arr.push_back(num);
    }

    for (auto &&i : arr)
        cout << "\t" << i << " ";

    // two dimesional array
    int row, col;
    cout << "\nEnter row number: ";
    cin >> row;
    cout << "\nEnter column number: ";
    cin >> col;

    vector<vector<int>> twoDarr(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int temp;
            cout << "Enter element for [" << i << "][" << j << "]: ";
            cin >> temp;
            twoDarr[i][j] = temp;
        }
    }

    cout << "\nTwo Dimensional Array: " << endl;
    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++)
            cout << twoDarr[i][j] << " ";
        cout << endl;

    return 0;
}
