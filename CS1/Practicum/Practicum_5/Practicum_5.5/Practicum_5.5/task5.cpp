//
//  task5.cpp
//  Practicum_5.5
//
//  Created by Jackson Warren on 9/23/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;
void passByVal(int);
void passByRef(int& x);

void passByVal(int x)
   {
       x++;
       cout << "In passByVal\nx= " << x << endl;
   }

void passByRef(int& x)
{
    x++;
    cout << "In passByRef\nx = " << x << endl;
}


int main(int argc, const char * argv[]) {

    int x = 10;
    passByVal(x);
    cout << "After calling function passByVal\nx = " << x << endl;
    
    passByRef(x);
    cout << "After calling passByRef\nx = " << x << endl;
        
    
    
    return 0;
}
