//
//  task2a.cpp
//  Task 2 (A)
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    // Now for Task 2 (task2a.cpp)
    
    
    // a)
    {
        double x, sum = 0;
        
        while (x != -1)
        {
            cout << "Give integer: ";
            cin >> x;
            sum += x;
        }
        cout << "Sum of Task 2 is: " << sum << endl;
    }
    
    // d)
    
    {
        double x, sum = 0;
        
        cout << "Give integer(2): ";
        cin >> x;
        
        while (x != -1)
        {
            sum += x;
            cout << "Give integer(2): ";
            cin >> x;
        }
        cout << "Sum of Task 2 is: " << sum << endl;
    }
    
    
    
    
    return 0;
}
