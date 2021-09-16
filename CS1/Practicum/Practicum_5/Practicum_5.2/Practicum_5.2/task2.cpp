//
//  task2.cpp
//  Practicum_5.2
//
//  Created by Jackson Warren on 9/19/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
using namespace std;

int getAge();

int main(int argc, const char * argv[]) {

    int age;
    
    cout << "Enter your age: ";
    age = getAge();
    
    while(age < 0 || age > 120)
    {
        cout << "\nYou entered an invalid age!\n";
        cout << "\nEnter your age: ";
        cin >> age;
}
    cout << "\nAre you really " << age << " old or did you make a mistake?\n" << endl;
    
    return 0;
}

int getAge(){
    int age;
    cin >> age;
    return age;
}
