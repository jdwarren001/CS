//
//  main.cpp
//  Comp_3
//
//  Created by Jackson Warren on 11/4/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {

    int numbs[1000];
    srand(time(NULL));
    bool swapped = false;
    
    for (int i = 0; i < 1000; i++)
    {
        numbs[i] = 511317 * rand() % 100000;
    }
    
    for (int i = 0; i < 1000; i++)
    {
        swapped = false;
        for (int j = 0; j < 1000; j++)
        {
            if (numbs[j] > numbs[j + 1])
            {
                swap (numbs[j], numbs[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    
    for (int x = 0; x < 1000; x++)
        cout << numbs[x] << ' ';
}
    
