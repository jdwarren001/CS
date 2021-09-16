//
//  task1.cpp
//  Practicum_4.1
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    
    // b) Task 1 (task1a.cpp)
    {
    int num, i = 1, sum;
    
    cout << "Give pos int: ";
    cin >> num;
    
    while (i <= num)
    {
        sum += i;
        i++;
        }
    cout << "Sum is: " << sum << endl;
    }
    
    // d) task 1
    
    {
        int num, i = 2, sum;
        cout << "Give pos int: ";
        cin >> num;
        while (i <= num)
        {
            sum += i;
            sum = sum / 2;
            sum = sum * 2;
            i += 2;
        }
        cout << "Sum of even integers from 1 to " << num << " is: " << sum << endl;
    }

    
    
    return 0;
}
