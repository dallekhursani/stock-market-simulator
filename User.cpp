#include "User.h"
#include <iostream>

using namespace std;

// Constructor to initialize user with a name and an initial balance
User::User(string userName, double initialBalance) {
    name = userName;
    balance = initialBalance;
}

// Method to buy stock for the user
void User::buyStock(const Stock& stock, int quantity) {
    double totalCost = stock.getPrice() * quantity;

    if (totalCost <= balance) {
        // Add stock to the user's portfolio
        bool stockFound = false;
        for (auto& s : stocks) {
            if (s.getName() == stock.getName()) {
                s.buyStock(quantity);
                stockFound = true;
                break;
            }
        }

        if (!stockFound) {
            Stock newStock(stock.getName(), stock.getPrice());
            newStock.buyStock(quantity);
            stocks.push_back(newStock);
        }

        // Deduct the cost from the user's balance
        balance -= totalCost;
        cout << "Bought " << quantity << " shares of " << stock.getName() << endl;
    } else {
        cout << "Not enough balance to buy stock." << endl;
    }
}

// Method to sell stock for the user
void User::sellStock(const Stock& stock, int quantity) {
    for (auto& s : stocks) {
        if (s.getName() == stock.getName()) {
            if (quantity <= s.getQuantity()) {
                // Sell the stock
                s.sellStock(quantity);

                // Add the sale amount to the balance
                double totalSale = stock.getPrice() * quantity;
                balance += totalSale;
                cout << "Sold " << quantity << " shares of " << stock.getName() << endl;
                return;
            } else {
                cout << "Not enough shares to sell." << endl;
                return;
            }
        }
    }

    cout << "Stock " << stock.getName() << " not found in portfolio." << endl;
}

// Method to get the portfolio value of the user (sum of stock values + balance)
double User::getPortfolioValue() const {
    double portfolioValue = balance;

    for (const auto& s : stocks) {
        portfolioValue += s.getPrice() * s.getQuantity();
    }

    return portfolioValue;
}

// Method to display the user's portfolio
void User::displayPortfolio() const {
    cout << "User: " << name << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Portfolio:" << endl;

    if (stocks.empty()) {
        cout << "No stocks owned." << endl;
    } else {
        for (const auto& s : stocks) {
            cout << s.getName() << " - " << s.getQuantity() << " shares at $" << s.getPrice() << " each" << endl;
        }
    }
}

// Getter for the user's name
string User::getName() const {
    return name;
}
