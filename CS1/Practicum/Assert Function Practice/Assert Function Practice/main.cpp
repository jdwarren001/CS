//
//  main.cpp
//  Assert Function Practice
//
//  Created by Jackson Warren on 9/3/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <iomanip> // used for two decimal places

using namespace std;

int main(int argc, const char * argv[]) {
    
    int accountNumber, numberOfPremiumChannels, numberOfBasicConnections;
    char customerType;
    double amountDue;
    
    const double rBillProcessingFee = 4.50;
    const double rBasicServiceCost = 20.50;
    const double rCostOfaPremiumChannel = 7.50;
    
    const double bBillingProcessingFee = 15.00;
    const double bBasicServiceCost = 75.00;
    const double bBasicConnectionCost = 5.00;
    const double bCostOfaPremiumChannel = 50.00;
    
    //sets variables to two decimals for everything inside french braces
    cout << setprecision(2) << fixed;
    
    //formulas for residential
    amountDue = rBillProcessingFee + rBasicServiceCost + numberOfPremiumChannels * rCostOfaPremiumChannel;
    
    //formulas for business
    if (numberOfBasicConnections <= 10)
        amountDue = bBillingProcessingFee + bBasicServiceCost + numberOfPremiumChannels * bCostOfaPremiumChannel;
    else
        amountDue = bBillingProcessingFee + bBasicServiceCost + numberOfPremiumChannels * bCostOfaPremiumChannel;
    
    // computing business bill
    if (numberOfBasicConnections <= 10)
        amountDue = bBillingProcessingFee + bBasicServiceCost + numberOfPremiumChannels * bCostOfaPremiumChannel;
    else
        amountDue = bBillingProcessingFee + bBasicServiceCost + (numberOfBasicConnections - 10) * bBasicConnectionCost + numberOfPremiumChannels * bCostOfaPremiumChannel;
    
    //beginning program
    cout << "R (Residential Customer),"; cout << " B (Business Customer)" << endl;
    cout << "Your customer type: ";
    cin >> customerType;
    cout << "\n\nAccount Number: ";
    cin >> accountNumber;
    cout << endl << endl;
    
    switch (customerType)
    {
        case 'R':
        case 'r':
            cout << "Number of premium channels: "; cin >> numberOfPremiumChannels;
            //calculations above
            cout << "\n\nBilling amount: " << amountDue << " for account " << accountNumber << "." << endl << endl;
            break;
            
        case 'B':
        case 'b':
            cout << "Numebr of basic service connections: "; cin >> numberOfBasicConnections;
            cout << endl << endl;
            cout << "Enter number of premium channels: "; cin >> numberOfPremiumChannels;
            cout << endl << endl;
            //calculations above
            cout << "Amount due: " << amountDue << " on account " << accountNumber << "." << endl << endl;
            break;
        
        default:
            cout << "Invalid customer type, try again." << endl << endl;
    }
    
  
    
    
    
    
    
    
    
    return 0;
}
