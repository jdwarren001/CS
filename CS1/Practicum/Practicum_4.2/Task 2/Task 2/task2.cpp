//
//  task2.cpp
//  Task 2
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
 
    int num = 0, max;
    
    cout << "Input a number: ";
    cin >> max;
    
    cout << "Number\tSquare\tCube" << endl;
    cout << "_______\t______\t____" << endl;
    
    for (num = 0; num <= max; num++)
        cout << num << '\t'
        << num * num << '\t'
        << num * num * num << endl;
    
    
    
    return 0;
}
