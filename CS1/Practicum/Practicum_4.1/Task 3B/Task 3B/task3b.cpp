//
//  task3b.cpp
//  Task 3B
//
//  Created by Jackson Warren on 9/9/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int  age1, age2, sum, average, sum2, m = 0;
    
    cout << "Input you and your partners age for  couple " << m + 1 << ": ";
    cin >> age1 >> age2;
    
    while (!cin.eof())
    {
        m = ++m;
        sum = age1 + age2;
        sum2 += sum;
        cout << "Input you and your partners age for  couple " << m + 1 << ": ";
        cin >> age1 >> age2;

    }
    average = sum2 / ( m * 2 );
    cout << "\n\nThe average of the age group given is: " << average << endl << endl;
    
    return 0;
}
