//
//  task2.cpp
//  Practicum_6.2
//
//  Created by Jackson Warren on 9/25/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
void printPattern(int, char);

char arraySymbol[5] = {'$', '@', '*', '^', '#'};
int arraySize[5] = {5, 6, 7, 8, 9};


void printPattern(int n, char symbol)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = r; c < n; c++)
            cout << symbol;
        for (int c = n-r; c < n; c++)
            cout << ' ';
        for (int c = n-r; c < n; c++)
            cout << ' ';
        for (int c = r; c < n; c++)
            cout << symbol;
        cout << endl;
    }
    
    for (int r = 1; r <= n; r++)
    {
        for (int c = 0; c < r; c++)
            cout << symbol;
        for (int c = r; c < n; c++)
            cout << ' ';
        for (int c = r; c < n; c++)
            cout << ' ';
        for (int c = 0; c < r; c ++)
            cout << symbol;
        cout << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    /*
    int n;
    char symbol;
    
    printPattern(n, symbol);
    */
    for (int i = 0; i < 5; i++)
    {
        printPattern(arraySize[i], arraySymbol[i]);
    }
    
    return 0;
}
