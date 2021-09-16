//
//  main.cpp
//  Ladder (1.4)
//
//  Created by Jackson Warren on 11/12/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int calc(double, double);

double h = 0.0;
double v = 0.0;
const double pi = 3.1415926535897932384626433832795028841971693993751;

int main(int argc, const char * argv[]) {
    
    //input
    cin >> h >> v;
    
    //tester
    if (0 > h || h > 10001 || v < 0 || v > 90)
    {
        cout << "\n\tERROR.\n";
        cin >> h >> v;
    }
    
    cout << calc(h, v) << endl << endl;
    
    
    return 0;
}


int calc(double h, double v)
{
    double l = 0.0;
    
    l = h / sin((v * pi) / 180); // have to convert the sin equation to degrees
    
    //cout << "1L: " << l << endl;
    
    l = ceil(l);
    
    //cout << "2L: " << l << endl;
    
    return l;
}
