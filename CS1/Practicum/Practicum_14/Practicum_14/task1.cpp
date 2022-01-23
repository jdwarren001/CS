//
//  task1.cpp
//  Practicum_14
//
//  Created by Jackson Warren on 11/21/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int recursive(int);

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    cout << "Input n: ";
    cin >> n;
    
    cout << recursive(n) << endl;
    
    return 0;
}

int recursive(int n)
{
    if (n == 1)
        return n;
    if (n > 1)
        return n + recursive(n - 1);
    return 0;
}
