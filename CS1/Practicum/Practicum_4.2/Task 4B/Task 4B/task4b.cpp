//
//  task4b.cpp
//  Task 4B
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
    
    while (number != 0)
    {
        if (number % 2 != 0)
            total++;
        number--;
    }
    
    cout << "Result: " << total << endl;
    
    
    
    return 0;
}
