//
//  main.cpp
//  Practicum_2.3
//
//  Created by Jackson Warren on 8/28/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//
/* Cindy uses the services of a brokerage firm to buy and sell stocks. The firm charges 1.5% service charges on the total amount for each transaction, buy or sell. When Cindy sells stocks, she would like to know if she gained or lost on a particular investment. Write a program that allows Cindy to input the number of shares sold, the purchase price of each share, and the selling price of each share. The program outputs the amount invested, the total service charges, amount gained or lost, and the amount received after selling the stock. */



#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int shares, a = 0;
    float pp, sp, invested, sc, gol, profit;
    // sp = selling price, pp = purchase price, sc = service charges, gol = gained or lost
    
    cout << "How many shares did you sell? \nShares sold: ";
    cin >> shares;
    
    
    while (a < shares) {
        cout << "\n\nFor share " << ++a << ", what was your purchase price? ";
        cin >> pp;
        
        cout << "\n\nWhat's the selling price for share " << a << "? "; cin >> sp;
        
        invested = (pp * .015) + pp;
        cout << "\nYou invested: $" << invested << endl << endl;
        
        sc = (pp * .015) + (sp * .015);
        cout << "Total service charges: $" << sc << endl << endl;
        
        gol = sp-pp;
        cout << "Your stock changed overall by: " << gol << endl << endl;
        
        profit = sp-pp-sc;
        cout << "Your overall profit would be: " << profit << endl << endl;
        
    }
    
    
    return 0;
}
