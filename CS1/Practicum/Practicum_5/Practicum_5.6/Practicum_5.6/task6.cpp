//
//  task6.cpp
//  Practicum_5.6
//
//  Created by Jackson Warren on 9/23/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
void swapFunc(int&, int&);

void swapFunc(int& a, int& b)
{
    int c;
    c = b;
    b = a;
    a = c;
}

int main(int argc, const char * argv[]) {
    
    int a, b;
    
    cout << "Enter a value 1: ";
    cin >> a;
    cout << "Enter a value 2: ";
    cin >> b;
    
    cout << "Before the swap: " << endl << "Value 1 : " << a << endl << "Value 2: " << b << endl;
    
    swapFunc(a, b);
    
    cout << "After swap: " << endl << "Value 1: " << a << endl << "Value 2: " << b << endl;
    
    
    return 0;
}
