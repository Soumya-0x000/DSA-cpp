#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {2, 7, 1, 3, 9};
    int size;

    cout << "How many elements do you want to insert: ";
    cin >> size;
    int insertingItemCount = size;

    while (size--) {
        int num;
        cout << "Enter number: " << "\t";
        cin >> num;
        arr.push_back(num);

        if (size == 0) {
            cout << "Here is your updated arr: ";
            for (int x : arr)
                cout << x << "\t";

            cout << "\nYour inserted items are: ";
            int arrSize = arr.size();

            vector<int> insertedItemArr = {};
            for (int i = arrSize - insertingItemCount; i < arrSize; i++) {
                int item = arr[i];
                insertedItemArr.push_back(item);
                cout << item << '\t';
            }

            char shouldPop;
            cout << "\nWant to popback inserted items?" << '\n' << "y/n: ";
            cin >> shouldPop;
            if (shouldPop == 'y') {
                string popMode;
                cout << "\nPop all inserted items or a specific one?";
                cout << "\nIf all then type 'a' or u can put the specific value to pop: ";
                cin >> popMode;

                if (popMode == "a") {
                    for (int k = 0; k < insertingItemCount; k++) {
                        arr.pop_back();
                    }
                } else if (popMode.find_first_not_of("0123456789") == string::npos) {
                    int value = atoi(popMode.c_str());

                    bool itemFound = false;
                    int mainArrSize = arrSize - insertingItemCount;
                    for (int i = 0; i < insertedItemArr.size(); i++) {
                        if (insertedItemArr[i] == value) {
                            arr.erase(arr.begin() + mainArrSize + i);
                            itemFound = true;
                            break;
                        }
                    }
                    if (!itemFound) {
                        cout << "\nYou entered a no that you didn't inserted previously";
                    }
                }
            }
        }
    }

    cout << "\n\nFinal array: ";
    for (auto &&i : arr)
        cout << "\t" << i << " ";

    cout << endl << endl << endl;
    return 0;
}
