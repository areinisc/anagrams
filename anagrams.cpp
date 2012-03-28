/*
 * Code written by Alex Reinisch and Nick Walker 
 * on the dates 27-30 March 2012.
 * Lab08 - Data Structures - Dr. Goldwasser
 */
#include<iostream>
#include<string>
using namespace std;

int runs(0);                    // Number of test cases the user will input
string initial(""), goal("");   // Input and expected output strings

int main() {
    cin >> runs;                // Store the number of test cases (runs)
    for (int i = 0; i < runs; i++) {
        cin >> initial;         // Store initial string
        cin >> goal;            // Store goal; expected permutation string
        cout << "Output for " << initial << goal << endl << "[" << endl;
        // RECURSION!
        cout << "]" << endl;
    }
    return 0;
}
