//
//  main.cpp
//  Practicum_12b
//
//  Created by Jackson Warren on 11/12/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

//Preprocessor Directives:
//One of the most useful uses of preprocessor directive is in code development debugging
//#ifdef DEBUG or #ifdef _DEBUG are used to handle some code that you use for debugging purposes. If
//you add #undef _DEBUG or similar to this at the very beginning of your code, the compiler will skip the
//code contained in #ifdef DEBUG /* bla bla */ #endif block.
#define DEBUG
#ifdef DEBUG
#define IS_IN_DEBUG true
#else
#define IS_IN_DEBUG false
#endif
//Would allow you to embed debug messages in your code which you can turn off with a
//simple command I.E.
//if ( IS_IN_DEBUG ) {
// cerr<<îDebug statement ì<<variable<<î value in variable x at line 43<<endl;
//}
enum OPERATIONS { ADD, MULTIPLY, SUBTRACT, QUIT };
typedef unsigned int number;

namespace MyFunctions
{
    number findSum(const number &, const number &);
    number findProduct(const number &, const number &);
    number findDifference(const number &, const number &);
}

void showMenu(void);
OPERATIONS getOperation(char);

int main(int argc, char* argv[])
{
    if ( IS_IN_DEBUG )
    {
        cout << "îDEBUG OUTPUT. î" << "îRunning in debug mode ì" << endl;
    }

    char input;
    number *num1; // a pointer to point that points to unsigned int aka number data type
    num1 = new number; //allocate memory in heap and store the address in num1
    number *num2 = new unsigned int; //declare num2 as a dynamic variable
    number *sum = new number; //declare sum as a dynamic variable
    // FIXME - Declare dynamic variables to store product and difference values
    number *product = new number;
    number *difference = new number;
    // - Must use them to store the returned values from functions
    OPERATIONS oper;
    //FIXME: Add do... while loop to continue the program until they want to quit
    do
    {
        cout << "\n\tClick enter to continue..." << endl;
        cin.get();
        //FIXME: call clear function defined using macros to clear the screen
        system("clear");
        showMenu();
        cin >> input;
        oper = getOperation(input);
        switch (oper)
        {
            case ADD:
                cout << "Enter two positive whole numbers separated by space: ";
                cin >> *num1 >> *num2;
                *sum = MyFunctions::findSum(*num1, *num2);
                printf("%u + %u = %u\n", *num1, *num2, *sum);
                break;
            // FIXME: complete the rest of the cases to perform other operations
            case SUBTRACT:
                cout << "Enter two positive whole numbers separated by space (larger number first): ";
                cin >> *num1 >> *num2;
                *difference = MyFunctions::findDifference(*num1, *num2);
                printf("%u - %u = %u\n", *num1, *num2, *difference);
                break;
            case MULTIPLY:
                cout << "Enter two positive whole numbers separated by space: ";
                cin >> *num1 >> *num2;
                *product = MyFunctions::findProduct(*num1, *num2);
                printf("%u * %u = %u\n", *num1, *num2, *product);
                break;
            case QUIT:
                cout << "See ya!" << endl;
                exit(0);
            default:
                break;
        }
        cin.ignore(1000, '\n');
    } while(true);
    
    cout << "Good bye! Enter to exit the program...";
        cin.get();
        
    return 0;
}

void showMenu(void)
{
    cout << "Enter one of the following menu options [1-4]:\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Multiply two numbers\n";
    cout << "[3] Subtract one number from another\n";
    cout << "[4] Quit the program\n";
    cout << "What's your choice? ";
}

number MyFunctions::findSum(const number &n1, const number &n2)
{
    return n1+n2;
}

OPERATIONS getOperation(char choice)
{
    OPERATIONS op;
    switch(choice)
    {
        case '1':
            op = ADD;
        break;
        case '2':
            op = MULTIPLY;
            break;
        case '3':
            op = SUBTRACT;
            break;
        default:
            op = QUIT;
    }
    return op;
}
//FIXME: define findProduct function declared inside MyFunctions namespace
// function returns the product of two numbers provided
number MyFunctions::findProduct(const number &n1, const number &n2)
{
    return n1 * n2;
}

//FIXME: define findDifference function declared inside MyFunctions namespace
// return the value of second number subtracted from the first
number MyFunctions::findDifference(const number &n1, const number &n2)
{
    return n1 - n2;
}
