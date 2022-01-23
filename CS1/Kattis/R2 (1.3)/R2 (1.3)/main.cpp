//
//  main.cpp
//  R2 (1.3)
//
//  Created by Jackson Warren on 11/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int calc(int, int, int);

int main(int argc, const char * argv[]) {
    
    int r1 = 0, s = 0, r2 = 0;
    
    //cout << "R1 and S: ";
    cin >> r1 >> s;
    
    if (r1 > 1000|| s > 1000 || r1 < -1000 || s < -1000)
    {
        cout << "Too much, try again.";
        cin >> r1 >> s;
    }
    
    //cout << r1 << s << endl; // test
    
    cout << calc(r1, s, r2) << endl;
    
    return 0;
}


int calc(int r1, int s, int r2)
{
    r2 = (s * 2) - r1;
    return r2;
}
