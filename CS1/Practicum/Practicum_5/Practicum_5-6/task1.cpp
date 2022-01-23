//
//  task1.cpp
//  Practicum_5-6
//
//  Created by Jackson Warren on 9/19/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

void printStars();//a) goal is to make function named printStars with no parameters and does not take a value

int main(int argc, const char * argv[])
{
    cout << "Before the function call.\n";
    printStars();
    cout << "\nAfter function call." << endl;
    
    return 0;
}

void printStars(){
    // this now makes the function actually here, before, nothing was here and now, it can find nothing here and can call that nothing into the equation.
    int stars; // now we are putting stuff inside the function so it doesn't just come up blank.
    cout << "Inside printStars.\n" << endl;
    cout << "How many stars to print: ";
    cin >> stars;
    
    for (int i = 0; i < stars; i++)
        cout << '*' << endl;
}
