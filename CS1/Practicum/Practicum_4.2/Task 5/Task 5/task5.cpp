//
//  task5.cpp
//  Task 5
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //ii.
    int number, i, j;
    cout << "Input a number: ";
    cin >> number;
    
    
{
    for (i = 1; number >= i; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}
    for (i = number; i >= 1; i--)
    {
            for (j = 1; j <= i; j++)
        {
               if (j % 2 == 0)
                   cout << '.';
            else
                cout << '*';
        }
        cout << endl;
    }
        

    
    
    
    return 0;
}
