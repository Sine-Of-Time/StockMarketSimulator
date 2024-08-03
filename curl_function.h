#ifndef CURL_FUNCTIONS_H // Header guard: prevents multiple inclusions of this file
#define CURL_FUNCTIONS_H

#include <string>
#include <jsoncpp/json/json.h>
using namespace std;
using namespace Json;

// Declare functions 
string get_price(const string& ticker_symbol, const string& api);

Value get_stock_quote(const string& ticker_symbol, const string& api);

#endif // CURL_FUNCTIONS_H