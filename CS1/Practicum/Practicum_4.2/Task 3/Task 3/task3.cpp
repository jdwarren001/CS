//
//  task3.cpp
//  Task 3
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int maxi = 5, maxj = 4;
    int i, j, outerLoop, innerLoop;
    
    for (i = 0; i <= maxi; i++)
    {
        outerLoop++;
        cout << i;
    
        for (j = 0; j <= maxj; j++)
        {
            innerLoop++;
            cout << j << endl;
        }
    }

cout << "Outer: " << outerLoop << endl;
cout << "Inner: " << innerLoop << endl;
    
    
    
    
    return 0;
}
