#include "Market.h"
#include "User.h"
#include "Admin.h"
#include "News.h"
#include <iostream>
using namespace std;

int main() {
    Market market;
    User user;
    Admin admin;
    int choice;

    while (true) {
        cout << "\n--- Welcome to Stock Market Simulator ---\n";
        cout << "1. View Stocks\n2. Buy/Sell Stock\n3. View Portfolio\n4. Take Loan\n5. Admin Dashboard (if admin)\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            market.displayStocks();
        } else if (choice == 2) {
            // Handle Buy/Sell
        } else if (choice == 3) {
            user.viewPortfolio();
        } else if (choice == 4) {
            double amount;
            cout << "Enter Loan Amount: ";
            cin >> amount;
            user.takeLoan(amount);
        } else if (choice == 5) {
            admin.adminPanel(market);
        } else if (choice == 6) {
            user.saveToFile();
            break;
        }
    }

    return 0;
}

