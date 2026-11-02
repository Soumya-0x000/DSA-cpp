#include <iomanip>  // setw, left (output formatting)
#include <iostream> // cin, cout, endl
#include <string>   // to_string
#include <vector>   // vector

using namespace std;

int main() {
    // Ask the user for the size of the 2D array (rows x columns)
    int row, col;
    cout << "\nEnter row number: ";
    cin >> row;
    cout << "\nEnter column number: ";
    cin >> col;

    // Create a 2D vector with `row` rows; each row is a vector of `col` ints
    // (all values start at 0 until we fill them in)
    vector<vector<int>> twoDarr(row, vector<int>(col));

    // Fill the array: outer loop walks the rows, inner loop walks the columns
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int temp;
            cout << "Enter element for [" << i << "][" << j << "]: ";
            cin >> temp;
            twoDarr[i][j] = temp; // store the value at row i, column j
        }
    }

    cout << "\nTwo Dimensional Array: " << endl;

    // Header row: column indexes ([0], [1], ...) above their values.
    // `left` left-aligns the text inside each fixed-width field.
    // The first setw(7) prints an empty 7-char gap so the column labels
    // start exactly where the values start (after the row labels).
    cout << left << setw(7) << "";
    for (int j = 0; j < col; j++)
        // Build a label like "[0]" and pad it to 6 characters
        cout << setw(6) << ("[" + to_string(j) + "]");
    cout << endl;

    // Each row: row index on the left, then that row's values
    for (int i = 0; i < row; i++) {
        // Row label like "[0]" padded to 7 characters
        cout << setw(7) << ("[" + to_string(i) + "]");
        for (int j = 0; j < col; j++)
            // Each value padded to 6 characters so columns line up
            cout << setw(6) << twoDarr[i][j];
        cout << endl; // end of this row
    }

    cout << endl;

    return 0;
}

/*
 * WHAT THIS PROGRAM DOES
 * ----------------------
 * 1. Asks the user for the number of rows and columns.
 * 2. Creates a 2D vector of that size and asks the user to enter every
 *    element, showing its [row][column] position in the prompt.
 * 3. Prints the array as a table: column indexes across the top, row
 *    indexes down the left side, and the values aligned underneath.
 *
 * Example (2 x 2, input 45 32 25 86):
 *            [0]   [1]
 *     [0]    45    32
 *     [1]    25    86
 *
 * WHAT I LEARNED
 * --------------
 * - A 2D array can be built as a "vector of vectors": vector<vector<int>>.
 *   Its size is decided at runtime, so I don't have to fix it in advance
 *   like a plain int arr[3][3].
 * - Access is twoDarr[i][j]: i picks the row, j picks the column.
 * - Nested loops are the standard way to visit a 2D array: the outer loop
 *   goes over rows, the inner loop goes over the columns of that row.
 * - Braces matter! In my first version the outer for loop had no { },
 *   so `cout << endl` ran only once after all the loops instead of after
 *   every row, and everything printed on one line.
 * - A tab ('\t') depends on the terminal's tab stops, so it can look wider
 *   than expected. Fixed-width fields (setw) give the same layout everywhere.
 * - Building the labels as strings ("[" + to_string(i) + "]") lets me pad
 *   them as a single unit with setw. Printing "[", i and "]" separately
 *   would make setw apply to only the first piece.
 * - Printing a header and a row label first makes the table easier to read
 *   because every value's position is visible.
 *
 * METHODS / FUNCTIONS USED
 * ------------------------
 * vector<vector<int>> twoDarr(row, vector<int>(col))
 *     Creates `row` copies of a vector with `col` zeros each, giving a
 *     row x col grid.
 *
 * cin >> variable / cout << value / endl
 *     Read input, print output, and print a new line (plus flush).
 *
 * setw(n)   (from <iomanip>)
 *     Sets the minimum width of the NEXT printed item to n characters,
 *     padding with spaces. It only affects the very next output, so it
 *     must be repeated before each item.
 *
 * left      (from <iomanip> / <ios>)
 *     Makes padded output left-aligned (padding goes after the text).
 *     Unlike setw, it stays active for all later output, so it only needs
 *     to be written once. The default is right-aligned.
 *
 * to_string(n)   (from <string>)
 *     Converts a number to a std::string, e.g. 3 -> "3". Used to build
 *     the "[0]", "[1]" labels.
 *
 * string + string
 *     The + operator joins strings: "[" + to_string(j) + "]" -> "[0]".
 *     At least one side must be a std::string (not two raw "text"
 *     literals), which to_string() provides.
 */
