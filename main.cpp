#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include "functions.h"
#include "curl_function.h"
using namespace std;
using namespace Json;

int main() {
    bool quit=true;
    while (quit!=false) {
        string tck;
        cout << "Please Enter Ticker Symbol: ";
        cin >> tck;

        Value config;
        ifstream config_file("config.json", ifstream::binary);

        if (!config_file.is_open()) {
            cerr << "Could not open config." << endl;
            return 1;
        }

        config_file >> config;
        config_file.close();
        string api_key = config["api_key"].asString();
        string name, exchange, currency, ans;
        float open, high, low, close, volume, change, price;
        int amount;
        price = stof(get_price(tck, api_key));
        
        Value stock_data = get_stock_quote(tck, api_key);
        if (!stock_data.empty()) {
            name = stock_data["name"].asString();
            exchange = stock_data["exchange"].asString();
            currency = stock_data["currency"].asString();
            open = stof(stock_data["open"].asString());
            high = stof(stock_data["high"].asString());
            low = stof(stock_data["low"].asString());
            close = stof(stock_data["close"].asString());
            volume = stof(stock_data["volume"].asString());
            change = stof(stock_data["change"].asString());
        } else {
            cerr << "Could not fetch stock info." << endl;
            return 1;
        }
        print_data(name, exchange, currency, open, high, low, close, volume, change, price);
        ProfitLoss(open, close, name);
        Sendsignal(price, high, low, ans, amount);
        this_thread::sleep_for(chrono::milliseconds(3000));
        quit=ContinueSim();
    }    
    printTerminationMessage();
    return 0;
}