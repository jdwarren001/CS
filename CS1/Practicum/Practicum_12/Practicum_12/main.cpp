//
//  main.cpp
//  Practicum_12 (Polish Calc)
//
//  Created by Jackson Warren on 11/5/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip> // need for decimals

using namespace std;

const int num = 20;
double stackArray[num] = {0.0};
double e = 0;

void push(double);
double pop();
bool isvalidinput(string);
void add();
void subtract();
void multiply();
void division();
void power();
void sqrt();
void enter();

int counter = 0;

int main(int argc, const char * argv[]) {
    
    char cstring[256] = "";
    char *pch;

    cout << "Input numbers: ";
    cin.getline(cstring, 256, '\n'); // grabs all chars and spaces
    cout << endl;
    
    cout << "Your Input: ";
    for (int i = 0; i < sizeof(cstring); i++) // throwing it back out to make sure same input
        cout << cstring[i];
    cout << endl;
    
    pch = strtok(cstring, " ");
    while (pch != NULL)
    {
        if (isdigit(*pch)) // testing to see if the chars gotten are numbers
         {
             double n = atof(pch); // atoi converts the char into an int
             //cout << "\nNumber " << n << endl;
             push(n);
         }
        // if not number
        else
        {
            switch (*pch)
            {
                case '=':
                    cout << setprecision(10) // sets to 10 decimals
                         << "\nYOUR ANSWER IS: " << pop() << endl << endl;
                    break;
                case '/':
                case 'd':
                case 'D':
                    division();
                    break;
                    
                case '*':
                case 'm':
                case 'M':
                    multiply();
                    break;
                    
                case '+':
                case 'A':
                case 'a':
                    add();
                    break;
                    
                case '-':
                case 's':
                case 'S':
                    subtract();
                    break;
                
                case 'r':
                    sqrt();
                    break;
                    
                case 'p':
                case '^':
                    power();
                    break;
                    
                case 'e':
                case 'E':
                    enter();
                    break;
                    
                default:
                    cout << "\tERROR. INCORRECT INPUT at " << pch << ".\n\n";
                    
            }
        }
        pch = strtok(NULL, " ");
    }
    
    
    return 0;
}



void push (double n) // stacking more
{
    if (counter > num - 1)
    {
        cout << "\t(1)There has been an error with the stacking program..." << endl;
        exit(1);
    }
    else
    {
        stackArray[counter] = n;
        counter++;
    }
}

double pop () // taking off the top
{
    if (counter <= 0)
    {
        cout << "\n\t(2)There has been an error with the stacking program..." << endl;
        exit(1);
    }
    else
    {
        double temp = 0.0;
        counter--;
        temp = stackArray[counter];
        stackArray[counter] = 0.0;
        e = temp;
        return temp;
    }
}

void add()
{
    push(pop() + pop());
}

void subtract()
{
    double y = pop(), x = pop();
    push(x - y);
}

void multiply()
{
    push(pop() * pop());
}

void division()
{
    double y = pop(), x = pop();
    push(x/y);
}

void power()
{
    double y = pop(), x = pop();
    push(pow(x,y));
}

void sqrt()
{
    push(sqrt(pop()));
}

void enter()
{
    push(e);
}
