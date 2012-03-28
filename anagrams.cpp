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
string stack(""), output(""), moves("");    // other necessary strings

void solve(const string& goal,  // the goal string
        const string& I,        // unused portion of "initial" string
        const string& S,        // current stack sequence
        const string& O,        // (partial) output string
        const string& moves     // '++-+-' style trace of moves thus far
        ) {
    if (O == goal) {
        cout << moves << endl;
    }
    //else if (S != goal.substr(0,S.length())) {
    //    break;                  // Permutation doesn't match goal
    //}
    else {
        if (!I.empty()) {                       // PUSH //
            solve(  goal,                       // same goal
                    I.substr(1,I.length()-1),   // initial -1 from beginning
                    S.append(I[I.length()-1]),  // stack with push to end
                    O,                          // output unchanged
                    moves.append('+')           // moves with push char added
                 );  
        }
        if (!S.empty()) {                       // POP //
            solve(  goal,                       // same goal
                    I,                          // initial string unchanged
                    S.substr(0,S.length()-1),   // stack with pop from end
                    O.insert(1,S.substr(S.length(),1)), // output with stack.pop at beginning
                    moves.append('-')           // moves with pop char
                 );
        }
    }
}

int main() {
    cin >> runs;                // Store the number of test cases (runs)
    for (int i = 0; i < runs; i++) {
        cin >> initial;         // Store initial string
        cin >> goal;            // Store goal; expected permutation string
        cout << "Output for " << initial << goal << endl << "[" << endl;
        solve(goal, initial, stack, output, moves); // RECURSION!
        cout << "]" << endl;
    }
    return 0;
}
