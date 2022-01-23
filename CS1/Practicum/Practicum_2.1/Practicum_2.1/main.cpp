//
//  main.cpp
//  Practicum_2.1
//
//  Created by Jackson Warren on 8/28/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

/* Write a C++ program that prompts the user to input the elapsed time for an event in seconds. The program then outputs the elapsed time in hours, minutes, and seconds. (For example, if the elapsed time is 9630 seconds, then the output is 2:40:30.) */


#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int time, hours, minutes, seconds;

    cout << "Put the elapsed time of the event in seconds: ";
    cin >> time;
    
    hours = time/60/60;
    minutes = (time-hours*60*60)/60;
    seconds = time-(hours*60*60)-(minutes*60);
    
    cout << endl << "Time would be: " << hours << ":" << minutes << ":" << seconds << endl << endl;
    
    
    
    
    return 0;
}
