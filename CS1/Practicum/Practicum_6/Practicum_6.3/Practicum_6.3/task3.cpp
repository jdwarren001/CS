//
//  task3.cpp
//  Practicum_6.3
//
//  Created by Jackson Warren on 9/27/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;

int arrayNumbers[15] = {0, 0, 0, 0, 1, 1, 0, 0, 0, 7, 7, 7, 1, 1, 0};
int arrayNew[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};



int main(int argc, const char * argv[]) {
    
    int i = 0, temp, newVal = 0;
    
    for (int j = 0; j < 15; j = i)
    {
        temp = arrayNumbers[i];
        
        while (temp == arrayNumbers[i + 1])
            i++;
        
            {
            arrayNew[newVal] = temp;
            newVal++;
            i++;
            }
    }
    
    cout << arrayNew << endl; // how do you output an array?
    
    return 0;
}
