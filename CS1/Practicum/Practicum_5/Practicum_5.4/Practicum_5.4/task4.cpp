//
//  task4.cpp
//  Practicum_5.4
//
//  Created by Jackson Warren on 9/23/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
float greaterThan(float, float);



float greaterThan(float a, float b)
{
    if (a > b)
        cout << "\nThe lowest value is " << b << endl;
    else
        cout << "\nThe lowest value is " << a << endl;
    return 0;
}



int main(int argc, const char * argv[]) {
    
    float a, b;

    cout << "Enter value 1: ";
    cin >> a;
    cout << "\nEnter a value 2: ";
    cin >> b;
    
    cout << greaterThan(a, b);
    
    
    
    return 0;
}
