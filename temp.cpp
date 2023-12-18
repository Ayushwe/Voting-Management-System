#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to display the candidate list
void displayCandidateList() {
    cout << "Candidate List:" << endl;
    cout << "1. Ayush - Symbol: A" << endl;
    cout << "2. Apurv - Symbol: B" << endl;
    cout << "3. Anuj - Symbol: C" << endl;
}

int main() {
    const int maxVoters = 5;
    string voterNames[maxVoters];
    string selectedCandidates[maxVoters];

    // Declare variables to store user input
    string voterName, selectedCandidate;
    int voterId, age;

    // Simulate voting for the first ten voters
    for (int i = 0; i < maxVoters; ++i) {
        // Get user input for voter details
        cout<<endl;
        cout << "Enter voter name: ";
        getline(cin, voterName); // Using getline to handle names with spaces
        cout << "Enter Voter ID: ";
        cin >> voterId;
        cout << "Enter Age: ";
        cin >> age;

        // Check if the voter is eligible to vote
        if (age < 18) {
            cout << "Sorry, " << voterName << ", you are not eligible for voting as you are under 18 years old." << endl;
            --i;  // Retry the current iteration
        } else {
            cout << "Hello, " << voterName << "! You are eligible for voting. Your vote is important." << endl;

            // Display candidate list
            displayCandidateList();

            // Get user input for selected candidate
            cout << "Enter the symbol of your selected candidate (A, B, or C): ";
            cin >> selectedCandidate;

            // Process the selected candidate
            if (selectedCandidate == "A" || selectedCandidate == "B" || selectedCandidate == "C") {
                // Store the vote
                voterNames[i] = voterName;
                selectedCandidates[i] = selectedCandidate;
                cout << "Thank you! Your vote has been recorded." << endl;
            } else {
                cout << "Invalid candidate symbol. Please select a valid candidate." << endl;
                --i;  // Retry the current iteration
            }
        }

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Count the votes
    int voteCount[3] = {0}; // Index 0 for Ayush, 1 for Apurv, 2 for Anuj
    for (int i = 0; i < maxVoters; ++i) {
        if (selectedCandidates[i] == "A") {
            ++voteCount[0];
        } else if (selectedCandidates[i] == "B") {
            ++voteCount[1];
        } else if (selectedCandidates[i] == "C") {
            ++voteCount[2];
        }
    }

    // Declare the result
    cout << "\nElection Results:" << endl;
    cout << "Ayush received " << voteCount[0] << " votes." << endl;
    cout << "Apurv received " << voteCount[1] << " votes." << endl;
    cout << "Anuj received " << voteCount[2] << " votes." << endl;

    // Determine the winner
    if (voteCount[0] > voteCount[1] && voteCount[0] > voteCount[2]) {
        cout << "Ayush is the winner!" << endl;
    } else if (voteCount[1] > voteCount[0] && voteCount[1] > voteCount[2]) {
        cout << "Apurv is the winner!" << endl;
    } else if (voteCount[2] > voteCount[0] && voteCount[2] > voteCount[1]) {
        cout << "Anuj is the winner!" << endl;
    } else {
        cout << "It's a tie! No clear winner." << endl;
    }

    return 0;
}
