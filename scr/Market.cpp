#include "Market.h"
#include <iostream>

using namespace std;

// Method to add a stock to the market
void Market::addStock(const Stock& stock) {
    // Check if the stock already exists in the market
    for (const auto& s : stocks) {
        if (s.getName() == stock.getName()) {
            cout << "Stock " << stock.getName() << " already exists in the market." << endl;
            return;
        }
    }

    // Add stock to the market
    stocks.push_back(stock);
    cout << "Stock " << stock.getName() << " added to the market with price: $" << stock.getPrice() << endl;
}

// Method to remove a stock from the market
void Market::removeStock(const string& stockName) {
    for (auto it = stocks.begin(); it != stocks.end(); ++it) {
        if (it->getName() == stockName) {
            stocks.erase(it);
            cout << "Stock " << stockName << " removed from the market." << endl;
            return;
        }
    }

    cout << "Stock " << stockName << " not found in the market." << endl;
}

// Method to update the price of a stock
void Market::updateStockPrice(const string& stockName, double newPrice) {
    for (auto& s : stocks) {
        if (s.getName() == stockName) {
            s.setPrice(newPrice);
            cout << "Stock " << stockName << "'s price updated to: $" << newPrice << endl;
            return;
        }
    }

    cout << "Stock " << stockName << " not found in the market." << endl;
}

// Method to get a stock by its name
Stock* Market::getStockByName(const string& stockName) {
    for (auto& s : stocks) {
        if (s.getName() == stockName) {
            return &s;
        }
    }
    return nullptr;
}

// Method to display all the stocks in the market
void Market::displayMarket() const {
    if (stocks.empty()) {
        cout << "No stocks available in the market." << endl;
        return;
    }

    cout << "\nAvailable Stocks in the Market:\n";
    for (const auto& s : stocks) {
        cout << s.getName() << " - Price: $" << s.getPrice() << endl;
    }
}
