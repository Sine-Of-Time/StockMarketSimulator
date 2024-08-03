#include "functions.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void ProfitLoss(float open, float close, std::string name) {
    float percentage_change = ((close - open) / open) * 100;

    if (percentage_change > 0) {
        cout << "\n" + name + " has gained " << percentage_change << "%\n";
    } else if (percentage_change < 0) {
        cout << "\n" + name + " has loss " << percentage_change << "%\n";
    } else {
        cout << "\nThe " + name + " stocks has not changed" << "\n";
    }
}

void wantTransact(string ans, int amount, float price) {
    cout << "/nInput the number of shares to buy/sell: ";
    cin >> amount;
    cout << "\n Would you like to know the price of this stock? \n";
    cout << "Your Response: ";
    cin >> ans;
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    if (ans == "Y") {
        cout << "\nStock Price: " << amount * price << "\n";
    } else if (ans == "N") {
        
    } else {
        cout << "\nInvalid Choice\n";
    }
}

void print_data(string name, string exchange, string currency, float open, float high, float low, float close, float volume, float change, float price) {
    cout << "\nGenerating Data...\n\n";
    cout <<
        "Name: " << name << "\n" <<
        "Exchange: " << exchange << "\n" <<
        "Currency:" << currency << "\n" <<
        "Open price: " << open << "\n" <<
        "High price: " << high << "\n" <<
        "Low price: " << low << "\n" <<
        "Close price: " << close << "\n" <<
        "Volume:" << volume << "\n" <<
        "Change: " << change << "\n" <<
        "Current Price: " << price << "\n";
}

void Sendsignal(float price, float high, float low, string ans, int amount){
    if(price <= low){
        cout << "Buying Stock\n\n";
        wantTransact(ans, amount, price);
    }
    else if(price >= high){
        cout << "Selling Stock\n\n";
        wantTransact(ans, amount, price);
    }
    else{
        cout << "This stock should not be brought nor sold. \n\n";
    }
}