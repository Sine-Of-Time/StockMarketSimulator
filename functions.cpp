#include "functions.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Simply calculates a percentage and then displays it
void ProfitLoss(float open, float close, string name) {
    float percentage_change = ((close - open) / open) * 100;

    if (percentage_change > 0) {
        cout << "\n" + name + " has gained " << percentage_change << "%\n";
    } else if (percentage_change < 0) {
        cout << "\n" + name + " has loss " << percentage_change << "%\n";
    } else {
        cout << "\nThe " + name + " stocks has not changed" << "\n";
    }
}

void wantTransact(float price, float high, float low, string ans, int amount) {
    string shouldBuy;
    bool stopLoop=false;

    if(price <= low){
        cout << "Tip: This stock is doing well\n";
    }
    else if(price >= high){
        cout << "Tip: This stock is not doing well\n";
    }
    else{
        cout << "Tip: Not much activity for this stock" << endl;
    }

    while(stopLoop==false){
        cout << "Would you like to buy this stock?:"<< endl;
        cin >> shouldBuy;
        for(char &c : shouldBuy) {
                c = tolower(c); 
            }
        if(shouldBuy=="n")return;
        if(shouldBuy=="y"){
            stopLoop=true;
            break;
        }
        cout << "Invalid input. Please only enter Y or N." << endl;
    }

    cout << "Input the number of shares to buy/sell:" << endl;
    cin >> amount;
    cout << "You brought ";
    cout << amount;
    cout << " shares."<<endl;
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

bool ContinueSim(){
    while(true){
        string answer;
        cout << "Would you like to look at another an stock? Y/N:" << endl;
        cin >> answer;
        for (char &c : answer) {
            c = tolower(c); 
        }
        if(answer=="n")return false;
        if(answer=="y")return true;
        cout <<"Invalid Input, you can only enter y or n."<< endl;
    }
}

void printTerminationMessage() {
    cout << "Program is terminating." << endl;
}
