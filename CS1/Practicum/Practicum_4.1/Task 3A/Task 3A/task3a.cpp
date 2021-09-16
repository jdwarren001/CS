//
//  task3a.cpp
//  Task 3A
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    double x, sum = 0;
    
    cout << "Give integer: ";
    cin >> x;
    
    while (!cin.eof())
    {
        sum += x;
        cout << "Give integer: ";
        cin >> x;
    }
    cout << "Sum of Task 2 is: " << sum << endl;
    
    
    
    return 0;
}
