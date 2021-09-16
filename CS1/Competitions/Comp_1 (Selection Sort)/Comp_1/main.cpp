//
//  main.cpp
//  Comp_1
//
//  Created by Jackson Warren on 10/31/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    int numbs[100];
    int mini = 0;
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {

        numbs[i] = 511317 * rand() % 100;
     //if(numbs[i]<0)numbs[i]*=-1;
    }
    
    for (int i = 0; i < 99; i++)
    {
        mini = i;
        for (int j = i + 1; j < 100; j++)
        {
            if (numbs[j] < numbs[mini])
            {
                mini = j;
            }
            if (mini != i)
            {
                swap(numbs[mini], numbs[i]);
            }
        }
    }
    
        for (int i = 0; i < 100; i++)
            cout << numbs[i] << endl;
    
    
   return 0;
}
