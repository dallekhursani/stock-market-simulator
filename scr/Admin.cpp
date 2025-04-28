#include "Admin.h"
#include <iostream>
using namespace std;

void Admin::adminPanel(Market& market) {
    int choice;
    do {
        cout << "\n--- Admin Panel ---\n";
        cout << "1. Add New Stock\n2. Remove Stock\n3. Update Stock Price\n4. Exit Admin Panel\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string symbol;
            double price;
            cout << "Enter new stock symbol: ";
            cin >> symbol;
            cout << "Enter price: ";
            cin >> price;
            market.addStock(Stock(symbol, price));
            cout << "✅ Stock added.\n";
        } else if (choice == 2) {
            string symbol;
            cout << "Enter stock symbol to remove: ";
            cin >> symbol;
            market.removeStock(symbol);
            cout << "✅ Stock removed.\n";
        } else if (choice == 3) {
            string symbol;
            double price;
            cout << "Enter stock symbol to update: ";
            cin >> symbol;
            cout << "Enter new price: ";
            cin >> price;
            Stock* stock = market.findStock(symbol);
            if (stock) {
                stock->setPrice(price);
                cout << "✅ Stock price updated.\n";
            } else {
                cout << "Stock not found.\n";
            }
        }
    } while (choice != 4);
}
