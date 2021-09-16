//
//  main.cpp
//  Practicum_3.2
//
//  Created by Jackson Warren on 9/5/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

   /* Q4. To learn how nested for loops work, play computer on the following code fragmentsand determine, for each case, the exact output.
    (a) int j, j;for (i=1;i<=5;i++){for (j=1;j<=5;j++)cout << i*j << ‘ ‘;cout << endl;}
    (b) int i, j;for (i=1;i<=5;i++){for (j=1;j<=5;j++)cout << I << ‘ ‘;
        cout << endl;}
    (c) int i, j;for (i=1;i<=5;i++){for (j=1;j<=i;j++)cout << j << ‘ ‘;cout << endl;}
    (d) const int m = 10;const int n = 10;int i, j;for (i=1;i<=m;i++){for (j=1;j<=n;j++)cout << m*(i-1)+j << ‘ ‘;}cout << endl
    */
    
    
    // a)
    {
    int i, j;
    
    for (i = 1; i <= 5; i++)
        {
        for (j = 1; j <= 5; j++)
            cout << i * j << endl;
        }
    }
    // b)
    {
    int i, j;
    
    for (i=1;i<=5;i++)
        {
        for (j=1;j<=5;j++)
            cout << i;
        cout << endl;
        
        }
    }
    
    // c)
    {
    int i, j;
    
    for (i=1;i<=5;i++)
        {
        for (j=1;j<=i;j++)
            cout << j << ' ';
            cout << endl;}
    }
    
    // d)
    {
    const int m = 10;
    const int n = 10;
    int i, j;
    
    for (i=1;i<=m;i++)
        {
        for (j=1;j<=n;j++)
            cout << m*(i-1)+j << ' ';
        }
        cout << endl;
    }
    
    
    
    return 0;
}
