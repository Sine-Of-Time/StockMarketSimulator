#ifndef FUNCTIONS_H  // Header guard: prevents multiple inclusions of this file
#define FUNCTIONS_H

#include <string>     
#include <jsoncpp/json/json.h>
using namespace std;

// Declare functions 
void ProfitLoss(float open, float close, string name);
void wantTransact(float price, float high, float low, string ans, int amount);
void print_data(string name, string exchange, string currency, float open, float high, float low, float close, float volume, float change, float price);
void printTerminationMessage();
bool ContinueSim();

#endif // FUNCTIONS_H 
