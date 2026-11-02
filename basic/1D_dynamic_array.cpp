#include <cstdlib>  // atoi()
#include <iostream> // cin, cout
#include <vector>   // vector

using namespace std;

int main() {
    // Starting array with some pre-filled values
    vector<int> arr = {2, 7, 1, 3, 9};
    int size;

    // Ask the user how many new elements they want to append
    cout << "How many elements do you want to insert: ";
    cin >> size;
    // Remember the original count, because `size` is decremented in the loop below
    int insertingItemCount = size;

    // Loop runs `size` times (size-- evaluates the old value, then decrements)
    while (size--) {
        int num;
        cout << "Enter number: " << "\t";
        cin >> num;
        arr.push_back(num); // Append the entered number to the end of the array

        // size == 0 means this was the last iteration, so all inputs are in
        if (size == 0) {
            // Print the whole array (original + inserted elements)
            cout << "Here is your updated arr: ";
            for (int x : arr)
                cout << x << "\t";

            cout << "\nYour inserted items are: ";
            int arrSize = arr.size();

            // The inserted items are the last `insertingItemCount` elements of arr.
            // Copy them into a separate vector so we can search them later.
            vector<int> insertedItemArr = {};
            for (int i = arrSize - insertingItemCount; i < arrSize; i++) {
                int item = arr[i];
                insertedItemArr.push_back(item);
                cout << item << '\t';
            }

            // Ask whether the user wants to undo (remove) some inserted items
            char shouldPop;
            cout << "\nWant to popback inserted items?" << '\n' << "y/n: ";
            cin >> shouldPop;
            if (shouldPop == 'y') {
                // Read as a string so the user can type either 'a' or a number
                string popMode;
                cout << "\nPop all inserted items or a specific one?";
                cout << "\nIf all then type 'a' or u can put the specific value to pop: ";
                cin >> popMode;

                if (popMode == "a") {
                    // Remove every inserted item by popping from the back
                    for (int k = 0; k < insertingItemCount; k++) {
                        arr.pop_back();
                    }
                } else if (popMode.find_first_not_of("0123456789") == string::npos) {
                    // Input contains only digits, so treat it as a value to remove
                    int value = atoi(popMode.c_str());

                    bool itemFound = false;
                    // Index in arr where the inserted items begin
                    int mainArrSize = arrSize - insertingItemCount;
                    // Search only among the inserted items (not the original ones)
                    for (int i = 0; i < insertedItemArr.size(); i++) {
                        if (insertedItemArr[i] == value) {
                            // Map the position in insertedItemArr back to arr and erase it
                            arr.erase(arr.begin() + mainArrSize + i);
                            itemFound = true;
                            break; // Remove only the first match
                        }
                    }
                    if (!itemFound) {
                        cout << "\nYou entered a no that you didn't inserted previously";
                    }
                }
            }
        }
    }

    // Print the final state of the array
    cout << "\n\nFinal array: ";
    for (auto &&i : arr)
        cout << "\t" << i << " ";

    cout << endl << endl << endl;
    return 0;
}

/*
 * WHAT THIS PROGRAM DOES
 * ----------------------
 * 1. Starts with a vector {2, 7, 1, 3, 9}.
 * 2. Asks the user how many numbers to add, then reads and appends them
 *    one by one with push_back().
 * 3. After the last number is added, it prints the updated array and the
 *    list of items that were just inserted.
 * 4. Optionally lets the user undo the insertion:
 *      - 'a'      -> pops all the inserted items off the end (array returns
 *                    to its original contents).
 *      - a number -> removes the first inserted item equal to that number
 *                    (only inserted items are searched, never the original
 *                    ones). If it isn't found, a message is shown.
 * 5. Prints the final array.
 *
 * Concepts practiced: vector, push_back, pop_back, erase with iterators,
 * range-based for loops, and basic input validation with string::find_first_not_of.
 *
 * WHAT I LEARNED
 * --------------
 * - A vector is a resizable array: unlike a plain array, it grows and
 *   shrinks at runtime, so I can add/remove elements freely.
 * - Elements added with push_back() always go to the END, so the newly
 *   inserted items sit in the last `n` positions. That's how I located
 *   them using (arrSize - insertingItemCount).
 * - Removing from the back (pop_back) is cheap, O(1). Removing from the
 *   middle (erase) is more costly, O(n), because the elements after it
 *   must shift left.
 * - Iterators (arr.begin() + index) are how erase() knows which element
 *   to remove; erase() doesn't take a plain index.
 * - `while (size--)` uses the old value for the check, then decrements,
 *   so the loop runs exactly `size` times and `size` is 0 on the last pass.
 * - Save a value (insertingItemCount) before modifying the variable that
 *   holds it, otherwise the original is lost.
 * - Reading user input as a string lets one prompt accept different kinds
 *   of answers ('a' or a number), which I then validate before converting.
 *
 * METHODS / FUNCTIONS USED
 * ------------------------
 * vector<int> arr = {...}
 *     Creates a vector and initializes it with a list of values.
 *
 * arr.push_back(x)
 *     Adds x to the end of the vector (size grows by 1). Time: O(1) amortized.
 *
 * arr.pop_back()
 *     Removes the last element (size shrinks by 1). Returns nothing. Time: O(1).
 *
 * arr.size()
 *     Returns the number of elements currently in the vector.
 *
 * arr[i]
 *     Accesses the element at index i (no bounds checking). Time: O(1).
 *
 * arr.begin()
 *     Returns an iterator pointing to the first element. Adding an
 *     integer to it (arr.begin() + k) moves it to the k-th element.
 *
 * arr.erase(iterator)
 *     Removes the element at that iterator position and shifts all later
 *     elements one step left. Time: O(n).
 *
 * for (int x : arr) / for (auto &&i : arr)
 *     Range-based for loop: visits every element in order without needing
 *     an index. `auto &&` avoids copying each element.
 *
 * cin >> variable
 *     Reads a value typed by the user into the variable (whitespace-separated).
 *
 * cout << value
 *     Prints a value to the console. '\n' = new line, '\t' = tab.
 *
 * endl
 *     Prints a new line AND flushes the output buffer.
 *
 * popMode.find_first_not_of("0123456789")
 *     Returns the index of the first character in the string that is NOT
 *     a digit, or string::npos if every character is a digit. I use it to
 *     check that the input is a valid number.
 *
 * string::npos
 *     A special constant meaning "not found" / "no position".
 *
 * atoi(popMode.c_str())
 *     Converts a C-style string like "42" to the integer 42.
 *     c_str() gives the const char* that atoi() needs from a std::string.
 *
 * break
 *     Exits the loop immediately; used to stop after removing the first match.
 */
