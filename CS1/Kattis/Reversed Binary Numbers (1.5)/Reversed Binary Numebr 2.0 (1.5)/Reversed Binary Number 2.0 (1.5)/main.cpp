//
//  main.cpp
//  Reversed Binary Numebr 2.0 (1.5)
//
//  Created by Jackson Warren on 11/19/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void toBinary(int);
void converter();
void display();

const int maxNum = 30;
string binary1 = "", binary2 = "";
int output = 0;

int main(int argc, const char * argv[]) {
    
    int input = 0;
    
    cin >> input;
    
    if (input > 1000000001 || input < 0)
    {
        cout << "ERROR." << endl;
        exit(1);
    }
    
    toBinary(input);
    converter();
    cout << output << endl;
    
    display();
    
    return 0;
}


void toBinary(int input)
{
    //finds number of multipliers
    int highestvar = 0;
    for (int i = maxNum; i >= 0; i--)
    {
        if (input >= pow(2, i))
        {
            highestvar = i;
            break;
        }
    }
    
    //convert number to binary
    int temp = input;
    for (int i = highestvar; i >= 0; i--)
    {
        if (temp >= pow(2, i))
        {
            binary1 += "1";
            temp = temp - pow(2, i);
        }
        else
        {
            binary1 += "0";
        }
    }
}

void converter()
{
    char ch;
    int l = binary1.length();
    
    //flips bianry1 to binary2
    for (int i = 0; i < l; i++)
    {
        ch = binary1.at(i);
        binary2 = ch + binary2;
    }
    
    //converts to number
    for (int i = 0; i < l; i++)
    {
        int j = (l - 1) - i; // need to be going down, not up
        
        ch = binary2.at(i);
        if (ch == '1')
        {
            output = output + pow(2, j);
        }
    }
}

void display()
{
    cout << "(1)Binary of the given number = " << binary1 << endl << "(2)Binary of the found number = " << binary2 << endl;
}
