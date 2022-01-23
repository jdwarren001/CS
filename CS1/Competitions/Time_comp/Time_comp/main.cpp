//
//  main.cpp
//  Time_comp
//
//  Created by Jackson Warren on 12/3/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//


#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

using namespace std;
using namespace std::chrono;

const long maxSize = 2000000, range = 100000000;

void insertionSort();
void selectionSort();
void bubbleSort();

int main(int argc, const char * argv[]) {
    
    insertionSort();
    selectionSort();
    bubbleSort();
    
    return 0;
}


void insertionSort()
{
    long *numbs;
    numbs = new long[maxSize];
    
    long mini = 0;
    srand(time(NULL));

    for (long i = 0; i < maxSize; i++)
    {
        numbs[i] = 511317 * rand() % range;
    }
    
    auto start = high_resolution_clock::now();
    
    for (long i = 0; i < maxSize; i++)
    {
        mini = i;
        for (long j = i + 1; j < maxSize; j++)
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
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << endl << '\t' << "Insertion sort: " << duration.count() << " nanoseconds" << endl << endl;
    cout << endl << '\t' << '\t' << "Seconds: " << duration.count() * 0.000000001 << endl << endl;
    cout << endl << '\t' << '\t' << "Minutes: " << (duration.count() * 0.000000001) / 60 << endl << endl;
    
    delete [] numbs;
}


void selectionSort()
{

    long *numbs;
    numbs = new long[maxSize];
    srand(time(NULL));
    
    for (long i = 0; i < maxSize; i++)
    {
        numbs[i] = 511317 * rand() % range;
    }
    
    auto start = high_resolution_clock::now();
    
    {
        // algorythm
        long temp = 0;
        long j = 0;
        
        for (long i = 1; i < maxSize; i++)
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
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << endl << '\t' << "Selection Sort: " << duration.count() << " nanoseconds" << endl << endl;
    cout << endl << '\t' << '\t' << "Seconds: " << duration.count() * 0.000000001 << endl << endl;
    cout << endl << '\t' << '\t' << "Minutes: " << (duration.count() * 0.000000001) / 60 << endl << endl;

    delete [] numbs;
    
}


void bubbleSort()
{
    long *numbs;
    numbs = new long[maxSize];
    srand(time(NULL));
    bool swapped = false;
    
    for (long i = 0; i < maxSize; i++)
    {
        numbs[i] = 511317 * rand() % range;
    }
    
    auto start = high_resolution_clock::now();
    
    for (long i = 0; i < maxSize; i++)
    {
        swapped = false;
        for (long j = 0; j < maxSize; j++)
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
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << endl << '\t' << "Bubble Sort: " << duration.count() << " seconds" << endl << endl;
    cout << endl << '\t' << '\t' << "Seconds: " << duration.count() * 0.000000001 << endl << endl;
    cout << endl << '\t' << '\t' << "Minutes: " << (duration.count() * 0.000000001) / 60 << endl << endl;
    
    delete [] numbs;
    
}
