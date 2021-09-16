//
//  main.cpp
//  Symmetric Order (1.4)
//
//  Created by Jackson Warren on 11/6/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

const int num = 15;
string list[num] = {" "};
string listFinal[num] = {" "};
string finale[1000] = {" "};
int y = 1, finaleLength = 0;

void listOrg(int);

int main(int argc, const char * argv[]) {

    int n = 0;
    string name;
    
    //cout << "Give an n: ";
    cin >> n;
    
    while (n < 0 || n > num) // prevents errors
    {
        cout << "Too many n's. Try again: ";
        cin >> n;
    }
    
    while (n != 0)
    {
        for (int r = 0; r < num; r++)
        {
            list[r] = {}; // have to resest arrays
            listFinal[r] = {};
        }
        
        for (int i = 0; i < n; i++) // gets names in increasing length order
        {
            cin >> name;
            list[i] = name;
        }
        
        listOrg(n);
        
        /*
        for (int e = 0; e < num; e++) //TEST listFinal output
            cout << listFinal[e] << endl;
        */

        int i = 0;
        while (n <= num)
        {
            finale[finaleLength] = listFinal[i];
            finaleLength++;
            
            if (listFinal[i].empty())
            {
                finaleLength--;
                break;
            }
            i++;
        }
        
        //cout << "Give an n: ";
        cin >> n;
    }
    
    for (int i = 0; i < finaleLength; i++)
        cout << endl << finale[i];
    
    cout << endl;
    
    return 0;
}



void listOrg(int n) // puts first in first and second in last, moves to next pair
{
    
    int counter = n;
    int x = 1, j = 0;
    
    listFinal[0] = "Set " + to_string(y);
    y++;
    
    listFinal[x] = list[j];
    x++;
    j++;
    listFinal[counter] = list[j];
    counter--;
    j++;
    
    while (x <= counter)
    {
        listFinal[x] = list[j];
        if (x == counter)
            break;
        x++;
        j++;
        listFinal[counter] = list[j];
        counter--;
        j++;
    }
}

