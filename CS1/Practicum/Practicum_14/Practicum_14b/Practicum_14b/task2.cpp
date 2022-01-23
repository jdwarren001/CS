//
//  task2.cpp
//  Practicum_14b
//
//  Created by Jackson Warren on 11/21/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int fib(int);

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    cout << "Input n: ";
    cin >> n;
    
    cout << fib(n) << endl;
    
    return 0;
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n >= 2)
        return fib(n - 1) + fib(n - 2);
    return 0;
}
