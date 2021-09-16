//
//  task2b.cpp
//  Task 1B
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int x, sentinel;
    
    cout << "Input a sentinel: ";
    cin >> sentinel;
    
    cout << "\n\nInput your grade please: ";
    cin >> x;
    
    while ( x != sentinel )
    {
        if (x >= 90 && x <= 100)
            cout << "\nYou're grade is and 'A'.";
        if (x >= 80 && x < 90)
        cout << "\nYou're grade is and 'B'.";
        if (x >= 70 &&  x < 80)
            cout << "\nYou're grade is and 'C'.";
        if (x >= 60 && x < 70)
            cout << "\nYou're grade is and 'D'.";
        if ( x < 60)
            cout << "\nYou're grade is and 'F'.";
        if ( x < 0 || x > 100)
        cout << "\nInvalid input, try again." << endl << endl;
        
        cout << "\n\nInput your grade please: ";
        cin >> x;
        
    }
    
    
    return 0;
}
