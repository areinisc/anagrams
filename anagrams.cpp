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
        cout << moves << endl;  // output fully matches goal; print moves
    }
    else if (O != goal.substr(0,O.length())) {
        return;                 // output so far doesn't match goal
    }
    else {
        if (!I.empty()) {                           // PUSH //
            string i = I.substr(1,I.length()-1);
            string s = S + I[0];
            string m = moves + "+";
            solve(  goal,       // same goal
                    i,          // initial -1 from beginning
                    s,          // stack with push to end
                    O,          // output unchanged
                    m           // moves with push char added
                 );  
        }
        if (!S.empty()) {                           // POP //
            string s = S.substr(0,S.length()-1);
            string o = O + S[S.length()-1];
            string m = moves + "-";
            solve(  goal,       // same goal
                    I,          // initial string unchanged
                    s,          // stack with pop from end
                    o,          // output with stack.pop at beginning
                    m           // moves with pop char
                 );
        }
    }
}

int main() {
    cin >> runs;                // Store the number of test cases (runs)
    for (int i = 0; i < runs; i++) {
        cin >> initial;         // Store initial string
        cin >> goal;            // Store goal; expected permutation string
        cout << "Output for " << initial << " " << goal << endl << "[" << endl;
        solve(goal, initial, stack, output, moves); // RECURSION!
        cout << "]" << endl;
    }
    return 0;
}
