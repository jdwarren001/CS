//
//  main.cpp
//  Seven Wonders (1.4)
//
//  Created by Jackson Warren on 11/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

char deck[50] = {""};
int total = 0;

void calc(char[], int&);

int main(int argc, const char * argv[]) {
    
    char *pch;
    
    cin >> deck;
    cout << endl;
    
    pch = strtok(deck, " ");
    
    //test
    /*
    for (int i = 0; i < 50; i++)
        cout << deck[i] << endl;
     */
    
    calc(deck, total);
    
    cout << total << endl << endl;
    
    return 0;
}


void calc(char deck[], int &total)
{
    int t = 0, c = 0, g = 0, temp = 0, tt = 0, tg = 0, tc = 0;
    
    // add up all of the letters
    for (int i = 0; i < 50; i++)
    {
        if (deck[i] == 'T')
            t = t + 1;
        if (deck[i] == 'G')
            g = g + 1;
        if (deck[i] == 'C')
            c = c + 1;
    }
    
    //test
    /*
    cout << "T: " << t << endl;
    cout << "G: " << g << endl;
    cout << "C: " << c << endl;
    */
    
    tt = t;
    tc = c;
    tg = g;
    while (tt > 0 && tg > 0 && tc > 0) // temps to use as lowest number. ex: T = 3, G = 2, C = 1; c is lowest number and will terminate after adding 7 to temp once without changing t, c and g.
    {
        temp += 7;
        tt--;
        tc--;
        tg--;
    }
    
    //testers
    /*
    cout << "TEMP: " << temp << endl;
    */
    
    
    // final calc
    t = (t * t);
    g = (g * g);
    c = (c * c);
    
    total = t + c + g + temp;
}
