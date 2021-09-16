//
//  main.cpp
//  Comp_2, Insertion Sort
//
//  Created by Jackson Warren on 11/1/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main(int argc, const char * argv[]) {

    int numbs[1000];
    srand(time(NULL));
    
    for (int i = 0; i < 1000; i++)
    {
        numbs[i] = 511317 * rand() % 100000;
    }
    
    auto start = high_resolution_clock::now();
    
    {
        // algorythm
        int temp = 0;
        int j = 0;
        
        for (int i = 1; i < 1000; i++)
        {
            temp = numbs[i];
            j = i - 1;
            
            while (temp < numbs[j] && j >= 0)
            {
                numbs[j + 1] = numbs[j]; // moves members foreward
                j = j - 1;
            }
            
            numbs[j + 1] = temp; // asserts temp into proper place
        }
        
    }
    
   for (int x = 0; x < 1000; x++)
        cout << numbs[x] << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << endl << '\t' << duration.count() << " nanonseconds" << endl << endl;
    
    return 0;
}
