//
//  main.cpp
//  Reversed Binary Numbers (1.5)
//
//  Created by Jackson Warren on 11/13/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

void tobinary(int); //convert number into binary
void converter(); // reverse c string
int frombinary(int); // convert reversed string into int
void tester();


const int maxNum = 20;
string binary[maxNum];
string finale[maxNum];

int main(int argc, const char * argv[]) {
    
    int input = 0;
    
    cin >> input;
    
    if (input > 1000000 || input < 0)
    {
        cout << "\n\n\tERROR.\n";
        cin >> input;
    }
    
    tobinary(input);
    
    converter();
    
    cout << frombinary(input) << endl;
    
    tester(); // comment out to get rid of test
    
    return 0;
}

void tobinary(int input)
{
    //convert number to binary
    int temp = input;
    for (int i = maxNum; i >= 0; i--)
    {
        if (temp >= pow(2, i))
        {
            temp = temp - pow(2, i);
            binary[maxNum - (i + 1)] = '1';
        }
        else
        {
            binary[maxNum - i] = '0';
        }
    }
}


void converter()
{
    //reverse binary number
    int j = 0;
    for (int i = maxNum; i > 0; i--)
    {
        finale[j] = binary[i];
        j++;
    }
}

int frombinary(int input)
{
    //finds number of multipliers
    int temp = 0;
    for (int i = maxNum; i >= 0; i--)
    {
        if (input >= pow(2, i))
        {
            temp = i;
            break;
        }
    }
    
    cout << endl << "Temp: " << temp << endl;
    
    //convert binary number into actual number (reading it backwards)
    int output = 0;
    int j = temp + 1; // cant subtract temp for loop but need number to limit array
    
    for (int i = 0; i < j; i++)
    {
        if (finale[i] == "1")
        {
            output = output + pow(2, (temp - 1));
        }
        
        temp--;
        
        cout << "i: " << i << "," << " Output: " << output << "," << " finale[i]: " << finale[i] << endl;
    }
    return output;
}

void tester()
{
    
    //test binary array taken in
    cout << "Binary (1): ";
    for (int i = 0; i < maxNum; i++)
        cout << binary[i];
    cout << endl;

    //test to get same number out
    int tempBin = 0;
    for (int i = 0; i < maxNum; i++)
    {
        if (i == 20)
            tempBin = tempBin + pow(2, 0);
        if (binary[i] == "1")
            tempBin = tempBin + pow(2, maxNum - (i + 1));
    }
    cout << "Binary (1) converted: " << tempBin << endl;
    
    
    //test for binary reversal array
    cout << "Binary (2): ";
    for (int i = 0; i <= maxNum; i++)
        cout << finale[i];
    cout << endl;
}
