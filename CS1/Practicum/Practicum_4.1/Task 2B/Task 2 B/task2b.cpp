//
//  task2b.cpp
//  Task 2 B
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    // Task 2, part b
    
    
        double x, sum = 0, sentinel;
    
    cin >> sentinel;
        
        while ( sentinel == 0 )
        {
            sum += x;
            cout << "Give integer: ";
            cin >> x;
            
            if (x == sentinel)
                break;
        }
    cout << "Sum of Task 2 is: " << sum << endl;
    
    
    return 0;
}
