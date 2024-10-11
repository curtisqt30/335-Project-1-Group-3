//-----------------------------------------------------------------------------
// Tyler Acuna
// Tacuna@csu.fullerton.edu
// CPSC 335
//-----------------------------------------------------------------------------
// Notes:
//  -findPartnerPositions was intially void, but it was easier to read as a
//   an int (hence the return of -1).
//
//  -Opted to use vectors over arrays since it'll make creating test cases
//   easier.
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// Helper function to find the position of the expected partner in the row
int findPartnerPosition(const vector<int>& row, int partner) {
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] == partner) {
            return i;  // Return the index where the partner is sitting
        }
    }
    return -1;  // This return statement is a safeguard, but it's safe to assume it won't be reached
}

int connectCouples(vector<int>& row) {
    int swaps = 0;

    // Iterate through the row in pairs to check if couples are seated together
    for (int i = 0; i < row.size(); i += 2) {
        int person1 = row[i];  // First person in the current pair
        int expected_partner;

        // Determine the expected partner based on ID
        if(person1 % 2 == 0){
            expected_partner = person1 + 1; // person1 is even
        }
        else {
            expected_partner = person1 - 1; // person1 is odd
        }

        // Check if the next person is the correct partner
        if (row[i + 1] != expected_partner) {
            // The partner is not sitting next to person1, so we need to swap
            int partner_position = findPartnerPosition(row, expected_partner);  // Find the partner's current seat index

            // Swap the partner to sit next to person1
            swap(row[i + 1], row[partner_position]);
            swaps++;
        }
    }

    return swaps;  // Return the total number of swaps made
}

int main() {
    // Test case 1
    vector<int> row1 = {0, 2, 1, 3};
    cout << "Minimum swaps for row1: " << connectCouples(row1) << endl;  // Expected output: 1

    // Test case 2
    vector<int> row2 = {3, 2, 0, 1};
    cout << "Minimum swaps for row2: " << connectCouples(row2) << endl;  // Expected output: 0

    return 0;
}
