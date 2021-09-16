//
//  task3.cpp
//  Practicum_5.3
//
//  Created by Jackson Warren on 9/23/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
void passByVal(int);

void passByVal(int x)
{
    x++;
    cout << "In passByVal\nx= " << x << endl;
}


int main(int argc, const char * argv[]) {

    int x = 10;
    passByVal(x);
    cout << "After calling function passByVal\nx = " << x << endl;
    
    
    
    
    return 0;
}
