//
//  task4a.cpp
//  Task 4
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int number = 0, total = 0;
    
    cout << "Enter a number: ";
    cin >> number;
    
    for (; number != 0; number--)
    {
        if (number % 2 != 0)
            total++;
    }
    
    cout << "Result: " << total << endl;
    
    
    
    return 0;
}
