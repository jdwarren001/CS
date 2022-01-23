//
//  main.cpp
//  Server ()
//
//  Created by Jackson Warren on 11/19/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//Server

int main(int argc, const char * argv[]) {
    
    int T = 0, numTasks = 0, totNumTasks = 0;
    int minutes[50];
    
    cin >> numTasks >> T;
    
    //get all the array
    for (int i = 0; i < numTasks; i++)
    {
        cin >> minutes[i];
    }
     
    for (int i = 0; i < numTasks; i++)
    {
        int t = minutes[i];
        if (T - t >= 0)
        {
            T = T - t;
            totNumTasks++;
        }
        else
        {
            break;
        }
    }
    
    cout << totNumTasks << endl;
    
    return 0;
}

