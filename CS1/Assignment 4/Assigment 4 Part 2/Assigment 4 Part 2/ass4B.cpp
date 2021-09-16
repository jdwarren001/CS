//
//  ass4B.cpp
//  Assigment 4 Part 2
//
//  Created by Jackson Warren on 10/4/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void usedFunc(int &temp, int arrayUsed[]);
void compCalcFunc(int &temp2, int currentVal);
void usedFuncComp(int &temp2, int arrayUsed[], int currentVal);
void compWinFunc(int currentTotal, int arrayUsed[], int &temp2);
void compStopWin(int playerCurrentVal, int arrayUsed[], int &temp2);
int noWinPos(int arrayUsed[], int currentVal, int &temp2);


void usedFunc(int &temp, int arrayUsed[])
{
    bool flag = false;
    do //until flag = true;
    {
        if (arrayUsed[temp - 1] == 0)
        {
            arrayUsed[temp - 1] = temp;
            flag = true;
        }
        else
        {
            cout << "Invalid number, try again. \nYour turn: ";
            cin >> temp;
        }
    }while(flag == false);
}


void compCalcFunc(int &temp2, int currentVal)
{
    temp2 = (temp2 % 99) + 1;
    while (currentVal - temp2 < 0)
    {
        temp2 = rand();
        temp2 = (temp2 % 99) + 1;
    }
}

void usedFuncComp(int &temp2, int arrayUsed[], int currentVal)
{
    bool flag = false;
    do
    {
        if (arrayUsed[temp2 - 1] == 0)
        {
            arrayUsed[temp2 - 1] = temp2;
            flag = true;
        }
        else
        {
            temp2 = rand();
            compCalcFunc(temp2, currentVal);
        }
    }while(flag == false);
}



void compWinFunc(int currentVal, int arrayUsed[], int &temp2)
{
    
    if (arrayUsed[currentVal - 1] == 0)
    {
        temp2 = currentVal;
    }
    
}

void compStopWin(int playerCurrentVal, int arrayUsed[], int &temp2, int currentVal)
{
    
    if (arrayUsed[playerCurrentVal - 1] == 0 && currentVal - playerCurrentVal >= 0)
    {
        temp2 = playerCurrentVal;
    }
    
}

int noWinPos(int arrayUsed[], int currentVal, int &temp2)
{
    for (int i = 0; i <= currentVal; i++)
        if (arrayUsed[i] == 0)
        {
            temp2 = i;
            return temp2;
        }
    cout << "The computer has run out of options! You win!! :D \n\n"; 
    exit(1);
}


int main(int argc, const char * argv[]) {
    
    int arrayUsed[99];
    for(int i = 0; i < 100; i++)arrayUsed[i] = 0;

    int currentVal = 501;
    int playerCurrentVal = 501;
    int temp = 1, temp2 = 1;
    
    
    temp2 = rand();
    if (temp2 % 2 == 0) // coin toss
    {
        cout << "Player Turn: ";
        cin >> temp;
        while (temp < 0 || playerCurrentVal - temp < 0 || temp > 99)
        {
            cout << "Incorrect input. Try again: ";
            cin >> temp;
        }
        usedFunc(temp, arrayUsed);
        playerCurrentVal = playerCurrentVal - temp;
        cout << "Player current value is: " << playerCurrentVal << " \nComputer current value is: " << currentVal << endl << endl;
    }
    
    while (temp != 0)
    {
        temp2 = rand();
        compCalcFunc(temp2, currentVal);
        
        if (currentVal < 15) // figure this out
            noWinPos(arrayUsed, currentVal, temp2);
        if (playerCurrentVal < 99)
            compStopWin(playerCurrentVal, arrayUsed, temp2, currentVal);
        if (currentVal < 99)
            compWinFunc(currentVal,arrayUsed, temp2);
        usedFuncComp(temp2, arrayUsed, currentVal);
        
        currentVal = currentVal - temp2;
        cout << "Computer turn: " << temp2 << endl;
        
      
        cout << "Player Turn: ";
        cin >> temp;
        while (temp < 0 || playerCurrentVal - temp < 0 || temp > 99)
        {
            cout << "Incorrect input. Try again: ";
            cin >> temp;
        }
        usedFunc(temp, arrayUsed);
        playerCurrentVal = playerCurrentVal - temp;
        cout << "Player current value is: " << playerCurrentVal << " \nComputer current value is: " << currentVal << endl << endl;
        if (currentVal == 0)
            break;
        if (playerCurrentVal == 0)
            break;
    }
    
    if (playerCurrentVal == 0 && currentVal != 0) // make a both win scenario
        cout << "YOU GOT TO ZERO FIRST! YOU WIN!\n\n";
    if (currentVal == 0 && playerCurrentVal != 0)
        cout << "TOUGH BREAK! COMPUTER GOT TO ZERO FRIST! YOU LOSE!\n\n";
    if (playerCurrentVal < 0 || currentVal < 0)
        cout << "ERROR. Something went wrong...\n\n";
    if (temp == 0)
        cout << "You forfeit!! Computer Wins!\n\n";
    if (playerCurrentVal == 0 && currentVal == 0)
        cout << "YOU BOTH MANAGED TO GET TO 0 IN THE SAME NUMBER OF TURNS! IT'S A DRAW!" << endl << endl;
    
    
    return 0;
}
