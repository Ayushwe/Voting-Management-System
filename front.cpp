#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>  // Include the algorithm header for find_if

using namespace std;

// Candidate class to represent candidates
class Candidate {
public:
    Candidate(const string& name, char symbol) : name(name), symbol(symbol) {}

    char getSymbol() const {
        return symbol;
    }

    const string& getName() const {
        return name;
    }

private:
    string name;
    char symbol;
};

// Voter class to represent voters
class Voter {
public:
    Voter(const string& name, int voterId, int age) : name(name), voterId(voterId), age(age) {}

    const string& getName() const {
        return name;
    }

    int getVoterId() const {
        return voterId;
    }

    int getAge() const {
        return age;
    }

    void voteForCandidate(const Candidate& candidate) {
        selectedCandidate = candidate.getSymbol();
    }

    const string& getSelectedCandidate() const {
        return selectedCandidate;
    }

private:
    string name;
    int voterId;
    int age;
    string selectedCandidate;
};

// Function to display the candidate list
void displayCandidateList(const vector<Candidate>& candidates) {
    cout << "Candidate List:" << endl;
    for (const Candidate& candidate : candidates) {
        cout << candidate.getName() << " - Symbol: " << candidate.getSymbol() << endl;
    }
}

int main() {
    const int maxVoters = 5;

    // Create candidate objects
    vector<Candidate> candidates = {
        Candidate("Ayush", 'A'),
        Candidate("Apurv", 'B'),
        Candidate("Anuj", 'C')
    };

    // Create a vector to store voter objects
    vector<Voter> voters;

    // Simulate voting for the first ten voters
    for (int i = 0; i < maxVoters; ++i) {
        // Get user input for voter details
        cout << endl;
        cout << "Enter voter name: ";
        string voterName;
        getline(cin, voterName); // Using getline to handle names with spaces
        cout << "Enter Voter ID: ";
        int voterId;
        cin >> voterId;
        cout << "Enter Age: ";
        int age;
        cin >> age;

        // Check if the voter is eligible to vote
        if (age < 18) {
            cout << "Sorry, " << voterName << ", you are not eligible for voting as you are under 18 years old." << endl;
            --i;  // Retry the current iteration
        } else {
            cout << "Hello, " << voterName << "! You are eligible for voting. Your vote is important." << endl;

            // Display candidate list
            displayCandidateList(candidates);

            // Get user input for selected candidate
            cout << "Enter the symbol of your selected candidate: ";
            char selectedSymbol;
            cin >> selectedSymbol;

            // Find the selected candidate
            auto selectedCandidate = find_if(candidates.begin(), candidates.end(),
                [selectedSymbol](const Candidate& candidate) { return candidate.getSymbol() == selectedSymbol; });

            // Process the selected candidate
            if (selectedCandidate != candidates.end()) {
                // Create a voter object and vote for the candidate
                voters.emplace_back(voterName, voterId, age);
                voters.back().voteForCandidate(*selectedCandidate);
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
    for (const Voter& voter : voters) {
        char selectedSymbol = voter.getSelectedCandidate()[0];
        switch (selectedSymbol) {
            case 'A':
                ++voteCount[0];
                break;
            case 'B':
                ++voteCount[1];
                break;
            case 'C':
                ++voteCount[2];
                break;
        }
    }

    // Declare the result
    cout << "\nElection Results:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << candidates[i].getName() << " received " << voteCount[i] << " votes." << endl;
    }

    // Determine the winner
    int maxVotes = max(max(voteCount[0], voteCount[1]), voteCount[2]);
    if (maxVotes == voteCount[0]) {
        cout << candidates[0].getName() << " is the winner!" << endl;
    } else if (maxVotes == voteCount[1]) {
        cout << candidates[1].getName() << " is the winner!" << endl;
    } else if (maxVotes == voteCount[2]) {
        cout << candidates[2].getName() << " is the winner!" << endl;
    } else {
        cout << "It's a tie! No clear winner." << endl;
    }

    return 0;
}
