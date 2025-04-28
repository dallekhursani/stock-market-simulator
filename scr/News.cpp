#include "News.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void News::triggerNewsEvent(Market& market) {
    vector<string> positiveNews = {
        "launches new revolutionary product",
        "reports record-breaking profits",
        "receives major investment",
        "announces partnership with tech giant"
    };

    vector<string> negativeNews = {
        "faces major lawsuit",
        "reports heavy losses",
        "experiences major hack",
        "CEO resigns unexpectedly"
    };

    srand(time(nullptr));
    vector<Stock>& stocks = market.getStocks();

    if (stocks.empty()) {
        cout << "No stocks available for news events.\n";
        return;
    }

    int stockIndex = rand() % stocks.size();
    Stock& selectedStock = stocks[stockIndex];

    bool isPositive = rand() % 2;

    if (isPositive) {
        int newsIndex = rand() % positiveNews.size();
        cout << "📰 " << selectedStock.getSymbol() << " " << positiveNews[newsIndex] << "!\n";
        selectedStock.updatePrice(10);
    } else {
        int newsIndex = rand() % negativeNews.size();
        cout << "📰 " << selectedStock.getSymbol() << " " << negativeNews[newsIndex] << "!\n";
        selectedStock.updatePrice(-10);
    }
}
