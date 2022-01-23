//
//  ass4A.cpp
//  Assigment 4
//
//  Created by Jackson Warren on 10/1/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;

const int numBoxes = 150;

void operatingBoxes(int arrayBoxes[]) // where 0 = closed and 1 = open.
{
    int n = 2;
    for (int i = 0; i < numBoxes; i++)
    {
        int x = 0;
        
        for (int j = n - 1; j < numBoxes; j = n + (x * n) - 1)
        {
            if (arrayBoxes[j] == 0)
                arrayBoxes[j] = 1;
            else
                arrayBoxes[j] = 0;
          //cout << x << "  " << j << "  " << n << "  " << endl << endl;
            //used to check program
            x++;
        }
        
        n++;
        if (n > numBoxes)
            break;

    }
}



int main(int argc, const char * argv[]) {
    
    int arrayBoxes[numBoxes] = {0};

    operatingBoxes(arrayBoxes);
    
    for (int i = 0; i < numBoxes; i++)
        cout << arrayBoxes[i] << ' ';
    cout << endl << endl;
    
    
    return 0;
}
