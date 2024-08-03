#ifndef FUNCTIONS_H  // Header guard: prevents multiple inclusions of this file
#define FUNCTIONS_H

#include <string>     
#include <jsoncpp/json/json.h>
using namespace std;

// Declare functions 
void calculateProfitLoss(float openingPrice, float closingPrice, const string& assetName);

void processTransactionDecision(const string& decision, int quantity, float price);

void displayMarketData(const string& name, const string& exchange, const string& currency, 
                       float openingPrice, float highPrice, float lowPrice, float closingPrice, 
                       float volume, float change, float currentPrice);

void generateTradeSignal(float currentPrice, float highPrice, float lowPrice, 
                         const string& decision, int quantity);

#endif // FUNCTIONS_H 
