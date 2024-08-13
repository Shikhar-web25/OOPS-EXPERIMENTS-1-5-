#include <iostream>
using namespace std;

int main() {
    int votes[5] = {0};  // Array to count votes for candidates 1 to 5
    int spoiltBallots = 0;
    int ballot;

    cout << "Enter the ballots (enter 0 to end voting): " << endl;

    while (true) {
        cin >> ballot;

        if (ballot == 0) {
            break;  // End voting if the user enters 0
        } else if (ballot >= 1 && ballot <= 5) {
            votes[ballot - 1]++;  // Increment the vote count for the respective candidate
        } else {
            spoiltBallots++;  // Increment the spoilt ballot count
        }
    }

    // Display the results
    cout << "\nVote Count:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << i + 1 << ": " << votes[i] << " votes" << endl;
    }
    cout << "Spoilt Ballots: " << spoiltBallots << endl;

    return 0;
}