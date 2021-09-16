//
//  main.cpp
//  Practice 1.3, Speed Limit
//
//  Created by Jackson Warren on 11/1/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;


void hours(int, int, int);
void distance(int, int, int, int);


int main(int argc, const char * argv[]) {
    
    int distarray[10] = {};
    int n = 0, time = 0, mph = 0, temp = 0, dist = 0, totdist = 0, i = 0, tottime = 0;
    
    //cout << "Input the number of data sets (-1 to complete): ";
    cin >> n;
    
    while (n != -1)
    {
        while (n > 0)
        {
            //cout << "Input MPH and hour stopped at that speed: ";
            cin >> mph >> time;
            hours(time, temp, tottime);
            distance(mph, tottime, dist, totdist);
            n--;
        }
        
        distarray[i] = totdist;
        i++;
        
        totdist = 0; // clean up
        tottime = 0;
        temp = 0;
        
        //cout << "Input the number of data sets (-1 to complete): ";
        cin >> n;
    }
    
    for (int j = 0; j < i; j++)
        cout << endl << distarray[j] << " miles" << endl;
    
    return 0;
}


void hours(int time, int &temp, int &tottime) // calc the hours
{
    tottime = time - temp;
    temp = time;
}

void distance(int mph, int tottime, int dist, int &totdist) // calc the distance
{
    dist = mph * tottime;
    totdist += dist;
}
