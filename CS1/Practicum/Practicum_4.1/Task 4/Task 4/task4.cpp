//
//  task4.cpp
//  Task 4
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int x = 4, y = 5, z = 11;
    
{
    cout << "Situation 1: ";
    while (((z - x) % 4) != 0)
        {
        cout << z << ' ';
        z += 7;
        }
}
    cout << endl;
    
    // i.

{
    cout << "Situation 2: ";
    while (((z + y) % 3) != 0)
    {
        cout << z << ' ';
        z += 7;
    }
}
    cout << endl;
    
    // ii.
{
    cout << "Situation 3: ";
    while ((x * x + y * y) > z)
    {
        cout << z << ' ';
        z += 7;
    }
}
    cout << endl;
    
    //iii.
{
    cout << "Situation 4: ";
    while (((z % 3) != 0) && (z < 50))
    {
        cout << z << ' ';
        z += 7;
    }
}
    cout << endl;
    
    //iv.
    /*
{
    cout << "Situation 5: ";
    while (x + y == 9)
    {
        cout << z << ' ';
        z += 7;
    }
}
    cout << endl;
*/
    return 0;
}
