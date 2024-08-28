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
        cout << endl << i << " ";

    return 0;
}
