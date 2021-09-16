//
//  main.cpp
//  Practicum_2
//
//  Created by Jackson Warren on 8/26/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

//Consider the following program segment

//include statement(s)
//using namespace statement

//int main
//{
    //variable declaration
    //executable statements
    //return statement
//}
//make sure all the code you write complies with the C++ code style guide.
//Write C++ code to complete the main statement above.
//Write C++ statements that include the header files iostream.
//Write a C++ statement that allows you to use cin, cout, and endl without the prefix std::.
//Write C++ statements that declare the following variables: num1, num2, num3, and average of type int.
//Write C++ statements that store 125 into num1, 28 into num2, and -25 into num3.
//Write a C++ statement that stores the average of num1, num2, and num3, into average.
//Write C++ statements that output the values of num1, num2, num3, and average.
//Compile and run your program. Show me the output please.


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int num1, num2, num3, average;
    
    num1 = 125;
    num2 = 28;
    num3 = -25;
    
    average = (num1+num2+num3)/3;
    
    
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Number 3: " << num3 << endl;
    cout << "Average: " << average << endl;
    
    
    
    return 0;
}
