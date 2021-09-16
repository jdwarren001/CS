//
//  ass3.cpp
//  Assignment 3
//
//  Created by Jackson Warren on 9/23/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
int gcdFinder(int val1, int val2);
double decimalFinder(int, int);
string hexidecimalFinder(int, int);
char hexidecimalConv(int);


int gcdFinder(int val1, int val2) // frunction for part 1
{
    while (val1 % val2 != 0 && val2 % val1 != 0)
    {
        if (val1 > val2)
            val1 %= val2;
        else
            val2 %= val1;
     }
    
    if (val1 > val2)
        return val2;
    else
        return val1;
}

double decimalFinder(int a, int b)
{
    int lv = a / b, dec = 0, i;
    double num;

    for (i = 1; i <= 6; i++)
        {
     a = (a % b) * 10; // why into a? Explain.
     dec = (dec * 10) + (a / b);
        }
    num = static_cast <double> (dec); // much confusion
    num /= 1000000;
        
        return lv + num;
}

string hexidecimalFinder(int val1, int val2)
{
int lv = val1 / val2;
string hexa1, hexa2;
double dec = 1.0 * val1 / val2;

while (lv != 0)
{
    hexa1 = static_cast<string>(hexidecimalConv(lv % 16) + hexa1); // again what?
    lv /= 16;
}

lv = val1 / val2;

    for (int i = 0; i < 6; i++) // why the error?
    {
    dec -= lv;
    dec *= 16;
    lv = static_cast<int> (dec);
    
    if (lv == 0 && dec == 0)
        break;
    
    hexa2 = static_cast<string>(hexa2 + hexidecimalConv(lv)); // purpose?
    }
    
    hexa1 = static_cast<string>(hexa1 + '.' + hexa2); // again, confusion
    return hexa1;
}


char hexidecimalConv(int integer) // yo why the error messages? and why integer?
{
    switch(integer)
        {
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
            case 10:
                return 'A';
            case 11:
                return 'B';
            case 12:
                return 'C';
            case 13:
                return 'D';
            case 14:
                return 'E';
            case 15:
                return 'F';
            default:
                cout << endl << "ERROR WITH CONVERSION." << endl;
                return 'X';
        }
}

int main(int argc, const char * argv[]) {
    
    
{ // 1.
    int val1, val2, gcd;
    
    cout << "Give two intergers you wish to find the gcd of such that (a/b)." << endl;
    cout << "Value 1: ";
    cin >> val1;
    cout << "Value 2: ";
    cin >> val2;
    
    while (val1 < 0 || val2 < 0) // safe check
    {
        cout << "\nNo can do. No negative numbers. Give two other numbers: \n";
        cout << "Value 1: ";
        cin >> val1;
        cout << "Value 2: ";
        cin >> val2;
    }
    
    while (val1 == val2) // safe check
    {
        cout << "\nYour gcd is the same number, therfore, " << val1 << '/' << val2 << ", your (a/b) = 1. \n";
        cout << "\nGive the program something more difficult! Give two more numbers: \n";
        cout << "Value 1: ";
        cin >> val1;
        cout << "Value 2: ";
        cin >> val2;
    }
    
    gcd = gcdFinder(val1, val2);
    
    cout << "With your gcd being " << gcd  << ", the simplest form of the fraction (a/b) is: " << val1 / gcd << "/" << val2 / gcd << " respectively." << endl << endl;
}
    
    // 2.
{
    int a, b;
     
    cout << "\n(PART TWO) Give two integers you wish to divide such that (a/b): \n";
    cout << "Value 1: ";
    cin >> a;
    cout << "Value 2: ";
    cin >> b;
        
    if (a < 0 || b < 0 || b == 0) // safe check
    {
        cout << "\nNo can do. Give two other numbers: \n";
        cout << "Value 1: ";
        cin >> a;
        cout << "Value 2: ";
        cin >> b;
    }
    
    cout << "Your ending decimal would be: " << decimalFinder(a, b) << endl << endl;
        
}
    
    // 3.
    {
        int val1, val2;
        
     cout << "\n(Part 3) Give two numbers you wish to divide into a hexidecimal such that (a/b): \nValue 1: ";
     cin >> val1;
     cout << "Value 2: ";
     cin >> val2;
    
     
     if (val1 < 0 || val2 < 0)
     {
         cout << "\nSorry, no negative numbers. Give two more: \n";
         cin >> val1 >> val1;
     }
     
        cout << "Your hexidecimal would be: " << hexidecimalFinder(val1, val2) << endl;

    }
    
    return 0;
}
