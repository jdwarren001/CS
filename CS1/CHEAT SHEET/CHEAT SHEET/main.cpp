//
//  main.cpp
//  CHEAT SHEET
//
//  Created by Jackson Warren on 9/6/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cmath>


int main(int argc, const char * argv[]) {
    
    using namespace std;
    
    int a, b, d; // intergers
    double i, c; // decimals
    char customerType; // single digits that arent variables
    float e; // long rounded decimals
    string flipper; // long lines of speech made from string variables
    bool whammy; // usually used for T/F statements
    
    
    if (a<b)
        // staement
    
    for (i=2; i<10; i++)
        // like while loop but with more ramifications
        break;
    
    while (c > d)
        // as long as the staement is true, the loop will run.
        else
            // if the the statement is false, goes to the else
            break;
    
    
    switch (customerType)
    
        case 'a':
        case 'A':
    
        case 'b':
        case 'B':
    
    do
    {
        // any statement or operation (It will do this operation no matter what, stops if while is no longer true)
        
    } while (//this conditoin remains true)
             
            
             //cin.eof statements need a primer and and specific order of operations
             
             //primer; (as in, ask for the input of what you desire to calculate)
    while (!cin.eof())
             //(equations and everything needed to do algorythm)
             //(Now, restated primer to ask it again should the loop continue)
              // the while statment will run until user types "ctrl 'd'".
             
             
             int titleOfFunction(); // at very top with namespace
    int titleOfFunction(int variableOfFunction) // has to be above main()
             {
             //now begin serperate algorythm. Can call this algorythm later into function!! Will use a lot.
                 return 2 * x; // if looking for an equation, return what you want to end the program with.
                 return x; // could also just do this.
             } // -> go to FUN folder and Function Prac. to see more
        
             

             
#include <iomanip> //need this to manipulate the outputs
            cout << setw(5) << x << endl; // 5 digits max
             cout << fixed << showpoint << setprecision(2); // says it will show 0's after decimal (showpoint) and will always have 2 decimals after # (setprecision).
             
             cout.unsetf(ios::fixed); //this undoes any fixed permaters set. After this, all fixed go back to default settings.
    
    
    
    pow(2,3); // does 2^3ß !!!!! -> need cmath header
             
    //Input and outputs
             
             cin.get(varChar); // the next char character input would be stored in varChar... WARNING: this does take the char character and remove it. If you do a second .get, you'll take the imidiate next character. (includes spaces)
             istreamVar.putback(varChar); // puts back the extracted char from the get function just used
             
             cin.ignoore(int#, ch#); // ex. (100, \n)-- Basically, this is saying till 100 characters have been read or a newline has been made, it will ignore all inputs. Placed immidiately after the last statement you want. (Does not include spaces)
             //ex.
                     cin >> something
                     cin.ignore(5, '.');
                     cin >> //something hopefully with a '.' or 5 spaces
             
             ch = istreamVar.peek(); //same function as the .get except it doesn't actually take the char and only copies it into memory. (Leave () empty for now)
             //ex.
             cin >> (some chars);
             ch = cin.peek();
             cout << ch; // would display the first char seen
             
    // Arrays
             
             int arrayTitle[n]; // where n is a integer
             
    // structs
             
             struct structName
             {
        int gradePercentage;
        char grade;
        string sentence1; // any data type
             }; // need ; after
             
             student1 structName; // student1 is now a variable of structName
             
             // to set student one's grades
             student1.grade = 'A';
             // or
             cin >> student1.grade;
             
             // output
             cout << student1.grade;
             
             //using arrays
             structName arrayName[n]; //this means n number in list will follow guidlines of struct.
             
             
    //files
             
             char fname[56]; // for file name
             ifstream ifs; // renames ifstream to ifs
             
             cin.getline(fname, 56, '\n'); // grabs file name from user, max size, or stop at new line
             ifs.open(fname); // opens file
             
             if(!ifs.is_open)
             {
                cout << "Failure"; // if unable to open file correctly, fails
                exit (1);
             }
             
             char temp[128];
             
             ifs.getline(temp, 128, \n); // priming read, gets info to start loop
             
             while (!ifs.eof()) // while file is not at end
             {
                //write it up
        ex.
        
        ifs >> temp; // gets next thing from file
        DB[numDB] = new disc; // makes new struct, disc, for array DB at position numDB
        
        DB[numDB]->title = new char[strlen(temp+1)]; // this is saying in that array at for numDB = 0, while lookign at title, make a space to put something of the length of temp + \n
        strcpy(DB[numDB] -> title, temp); //this is saying copy the thing grabbed by temp with the getline, put it into the array DB[at spot numDB], put it in the target, what we want to put there. (target, source)
             }
             
             
        for (int i = 0; i < sizeof(cstring) && isalnum(cstring[i]); i++) // fails if not number or char
             isalpha() //fails if not letter
             isdigit() //fails if not digit
             isblank() // fails if not blank
             
             
             
    
    return 0;
}
