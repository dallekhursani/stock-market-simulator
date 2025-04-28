#include "Leaderboard.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Method to add a user to the leaderboard
void Leaderboard::addUser(const string& name, double portfolioValue) {
    // Check if the user already exists in the leaderboard
    for (auto& user : leaderboard) {
        if (user.name == name) {
            cout << "User " << name << " already exists in the leaderboard." << endl;
            return;
        }
    }

    // If the user does not exist, add them to the leaderboard
    leaderboard.push_back(User(name, portfolioValue));
    cout << "User " << name << " added to the leaderboard with portfolio value: $" << portfolioValue << endl;
}

// Method to update a user's portfolio value on the leaderboard
void Leaderboard::updateUserPortfolio(const string& name, double newPortfolioValue) {
    // Find the user in the leaderboard and update their portfolio value
    for (auto& user : leaderboard) {
        if (user.name == name) {
            user.portfolioValue = newPortfolioValue;
            cout << "User " << name << "'s portfolio value updated to: $" << newPortfolioValue << endl;
            return;
        }
    }

    // If the user is not found
    cout << "User " << name << " not found in the leaderboard." << endl;
}

// Method to display the leaderboard
void Leaderboard::displayLeaderboard() const {
    // Sort users by portfolio value in descending order
    vector<User> sortedLeaderboard = leaderboard;
    sort(sortedLeaderboard.begin(), sortedLeaderboard.end(),
        [](const User& a, const User& b) {
            return a.portfolioValue > b.portfolioValue;
        });

    // Display the leaderboard
    cout << "\nLeaderboard:\n";
    for (size_t i = 0; i < sortedLeaderboard.size(); ++i) {
        cout << (i + 1) << ". " << sortedLeaderboard[i].name
             << " - Portfolio Value: $" << sortedLeaderboard[i].portfolioValue << endl;
    }
}
