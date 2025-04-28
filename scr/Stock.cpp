#include "Stock.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor to initialize stock with a name and price
Stock::Stock(string stockName, double stockPrice) {
    name = stockName;
    price = stockPrice;
    quantity = 0;  // By default, we start with 0 quantity
}

// Method to buy the stock
void Stock::buyStock(int qty) {
    if (qty > 0) {
        quantity += qty;
        cout << "Bought " << qty << " shares of " << name << " at $" << price << " each." << endl;
    } else {
        cout << "Quantity must be positive to buy stock." << endl;
    }
}

// Method to sell the stock
void Stock::sellStock(int qty) {
    if (qty > 0 && qty <= quantity) {
        quantity -= qty;
        cout << "Sold " << qty << " shares of " << name << " at $" << price << " each." << endl;
    } else {
        cout << "Cannot sell more shares than owned or sell a non-positive quantity." << endl;
    }
}

// Method to update the price of the stock
void Stock::updatePrice(double newPrice) {
    if (newPrice > 0) {
        price = newPrice;
        cout << "Price of " << name << " updated to $" << price << "." << endl;
    } else {
        cout << "Price must be a positive number." << endl;
    }
}

// Method to get the current price of the stock
double Stock::getPrice() const {
    return price;
}

// Method to get the name of the stock
string Stock::getName() const {
    return name;
}

// Method to get the current quantity of stock owned
int Stock::getQuantity() const {
    return quantity;
}
