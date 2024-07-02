#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// A function to compare two cards based on their rank and suit
bool compare_cards(string a, string b, char trump) {
    // A map to store the rank values of each card
    unordered_map<char, int> rank_values = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    // If both cards have the same suit
    if (a[1] == b[1]) {
        // Compare their rank values
        return rank_values[a[0]] > rank_values[b[0]];
    }
    // If the first card is a trump card
    else if (a[1] == trump) {
        // It can beat any non-trump card
        return true;
    }
    // If the second card is a trump card
    else if (b[1] == trump) {
        // It can beat any non-trump card
        return false;
    }
    // If neither card is a trump card
    else {
        // No card can beat the other
        return false;
    }
}

// A function to reconstruct the rounds played in the game
void reconstruct_rounds(int n, char trump, vector<string> cards) {
    // A vector to store the possible rounds
    vector<vector<string>> rounds;
    // A boolean flag to indicate if a solution is found
    bool found = false;
    // Sort the cards in descending order based on the compare_cards function
    sort(cards.begin(), cards.end(), & {
        return compare_cards(a, b, trump);
    });
    // A recursive function to generate all possible combinations of rounds
    function<void(int, vector<string>, vector<bool>)> generate = & {
        // If a solution is already found, return
        if (found) return;
        // If all cards are used, check if the current combination is valid
        if (index == 2 * n) {
            // A boolean flag to indicate if the current combination is valid
            bool valid = true;
            // Loop through the current combination and check if each pair of cards is a valid round
            for (int i = 0; i < 2 * n; i += 2) {
                // If the second card cannot beat the first card, the current combination is invalid
                if (!compare_cards(current[i + 1], current[i], trump)) {
                    valid = false;
                    break;
                }
            }
            // If the current combination is valid, store it as a possible solution and set the found flag to true
            if (valid) {
                rounds.push_back(current);
                found = true;
            }
            // Return from the recursive function
            return;
        }
        // Loop through the remaining cards and try to add them to the current combination
        for (int i = 0; i < 2 * n; i++) {
            // If the card is not used yet, add it to the current combination and mark it as used
            if (!used[i]) {
                current.push_back(cards[i]);
                used[i] = true;
                // Recursively call the generate function with the next index
                generate(index + 1, current, used);
                // Backtrack and remove the card from the current combination and mark it as unused
                current.pop_back();
                used[i] = false;
            }
        }
    };
    // Call the generate function with the initial index, an empty vector, and a vector of false values
    generate(0, {}, vector<bool>(2 * n, false));
    // If no solution is found, print "IMPOSSIBLE"
    if (rounds.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    // Otherwise, print any possible solution
    else {
        for (auto round : rounds[0]) {
            cout << round << " ";
        }
        cout << "\n";
    }
}

// The main function
int main() {
    // Read the number of test cases
    int t;
    cin >> t;
    // Loop through each test case
    while (t--) {
        // Read the number of rounds, the trump suit, and the cards
        int n;
        char trump;
        vector<string> cards(2 * n);
        cin >> n >> trump;
        for (int i = 0; i < 2 * n; i++) {
            cin >> cards[i];
        }
        // Call the reconstruct_rounds function with the input
        reconstruct_rounds(n, trump, cards);
    }
    // Return 0 from the main function
    return 0;
}
