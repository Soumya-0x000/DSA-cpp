#include <iostream>
#include <vector>

using namespace std;

int main() {
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
