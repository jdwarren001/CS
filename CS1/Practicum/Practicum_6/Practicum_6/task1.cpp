//
//  task1.cpp
//  Practicum_6
//
//  Created by Jackson Warren on 9/25/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int size = 5;
    int score[size], max;
    
    cout << "How many values must you input? \nNumber of inputs: ";
    cin >> size;
    
    cout << "Enter " << size << " scores: \n";
    
    for (int i = 0; i < size; i++)
        cin >> score[i];
    max = score[0];
    for (int i = 0; i < size; i++)
    {
        if (score[i] > max)
            max = score[i];
    }
    
    cout << "Max score is: " << max << endl;
    
    
    
    
    return 0;
}
