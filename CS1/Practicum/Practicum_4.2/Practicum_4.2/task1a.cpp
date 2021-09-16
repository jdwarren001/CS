//
//  task1a.cpp
//  Practicum_4.2
//
//  Created by Jackson Warren on 9/11/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int x;
    
    do
    {
        cout << "\n\nInput your grade: ";
        cin >> x;
        
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
    } while (x <= 100 && x > 0);
    
    cout << "\nInvalid input, try again." << endl << endl;
    
    
    
    return 0;
}
