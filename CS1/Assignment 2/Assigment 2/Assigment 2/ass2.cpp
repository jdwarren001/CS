//
//  Assigment 2.cpp
//  Assigment 2
//
//  Created by Jackson Warren on 9/2/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//
/*Assignment 2

Due at 11.59pm, Sunday, September 14


Aim:
To write a C++ program to solve a calculation problem, including typing in the program, debugging and testing.

Procedure:
You are employed as a programmer for a firm which manufactures talking clocks. The hardware division has developed two chips: the first generates the current day and month plus the number of seconds since midnight; the second speaks the date and time when provided with English text for data. Thus, for the due date and time above, chip one yields 09, 14 and 86340. The second chip can speak "eleven fifty nine p m on september fourteenth". Your task is to write the code to take the output of chip one and produce the input for chip two.

A) You need three algorithms to:
1. Convert seconds to hours and minutes representing a time of day using a 12-hour clock.
2. Convert a two-digit number into its text representation.
3. Convert a numeric date into words.

If you wish to get some practice at algorithm design, you may attempt to work out the algorithms.
They can also be found in the document labelled algorithms.

B) Now you are to develop the program to solve the problem, utilising the four algorithms designed above. Your program should
1. Request a day and month and a number of seconds. (The year is not needed.)
2. Use algorithm 1 to convert seconds to the hours and minutes of a 12 hour clock.
3. Print out the time in the form hh:mm x.m., for example, 11:59 P.M.
4. Finally, using algorithm 2 and 3, print out the time and date in words. Note that times such as 10:15 would become "ten fifteen" while day 09/8 becomes "september eightth". Also 7:05 would be spoken as "seven oh five". Midnight is considered "twelve a m", while noon is "twelve p m". This will involve some cutting and pasting and removal of unnecessary cases, and the addition of a case to handle the situation of one digit minutes.

You can use only that material in the course up to and including the switch statement. Finally program cannot include loops or arrays. This assignment is aimed at testing your understanding of expressions, assignment, along with the if and switch control structures.
You will find the use of cut and paste to be most advantageous.
 */


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int seconds, hours, minutes, date, month, first_digit, second_digit, mfirst_digit, msecond_digit;

// A)
    
    
//1.
    cout << "What is the seconds of the current day (Where 12:00am = 0 seconds): ";
    cin >> seconds;
    
    hours = seconds / 60 / 60;
    minutes = (seconds - (hours * 60 * 60)) / 60;
    
    //need this to convert into 12 hour and not 24 hour clock.
    //Needed second if for less than 1 hour -> Dont know
    if (hours >= 12)
    {
        if (hours > 12 && hours <= 24)
        hours = hours - 12;
        cout << "The time would be " << hours << ":" << minutes << " P.M.";
        hours = hours + 12;
        if (hours == 12)
            cout << "The time would be " << hours + 12 << ":" << minutes << " P.M.";
        if (hours > 24)
            cout << "->Invalid input for seconds of day, try again.";
    }
    else
    {
        if (hours == 0)
            cout << "The time would be " << hours + 12 << ":" << minutes << " A.M.";
        else
        cout << "The time would be " << hours << ":" << minutes << " A.M.";
    }
    
    
//2.
    cout << "\n\n\nWhat is the date? \n\nMonth(Number form '1-12'): ";
    cin >> month;
    cout << "\n\nDay(1-31): ";
    cin >> date;
    
    // need all 12 months converted from numbers.
    
    if (month == 1)
        cout << "\nJanuary ";
    if (month == 2)
        cout << "\nFebruary ";
    if (month == 3)
        cout << "\nMarch ";
    if (month == 4)
        cout << "\nApril ";
    if (month == 5)
        cout << "\nMay ";
    if (month == 6)
        cout << "\nJune ";
    if (month == 7)
        cout << "\nJuly ";
    if (month == 8)
        cout << "\nAugust ";
    if (month == 9)
        cout << "\nSeptember ";
    if (month == 10)
        cout << "\nOctober ";
    if (month == 11)
        cout << "\nNovember ";
    if (month == 12)
        cout << "\nDecember ";
    if (month >= 12 || month <= 0)
        cout << "Invalid input for month. Try again. ";
  
//3. need to put date into words.
    
    first_digit = date / 10;
    second_digit = date % 10;
    
    //for all the teen (date) numbers
    if (first_digit == 1)
    {
        if (second_digit == 1)
            cout << "Eleventh, ";
        if (second_digit == 2)
        cout << "Twelfth, ";
        if (second_digit == 3)
        cout << "Thirteenth, ";
        if (second_digit == 4)
        cout << "Fourteenth, ";
        if (second_digit == 5)
        cout << "Fifteenth, ";
        if (second_digit == 6)
        cout << "Sixteenth, ";
        if (second_digit == 7)
        cout << "Seventeenth, ";
        if (second_digit == 8)
        cout << "Eighteenth, ";
        if (second_digit == 9)
        cout << "Nineteenth, ";
    }
    
    //now for numbers 20+
    if (first_digit == 2)
        cout << "Twenty ";
    if (first_digit == 3)
        cout << "Thirty ";
    if (first_digit > 3 || first_digit < 0)
        cout << "Invalid input for numbered day. Try again. ";
    
    //now on to second digits (date)
    if (first_digit == 0 || first_digit == 2 || first_digit == 3)
    {
        if (second_digit == 1)
            cout << "first, ";
        if (second_digit == 2)
            cout << "second, ";
        if (second_digit == 3)
            cout << "third, ";
        if (second_digit == 4)
            cout << "fourth, ";
        if (second_digit == 5)
            cout << "fifth, ";
        if (second_digit == 6)
            cout << "sixth, ";
        if (second_digit == 7)
            cout << "seventh, ";
        if (second_digit == 8)
            cout << "eighth, ";
        if (second_digit == 9)
            cout << "ninth, ";
    }
    
    //now for outputting the time in words
    
    if (hours == 0 )
        cout << "Twelve";
    if (hours == 1 || hours == 13)
        cout << "One";
    if (hours == 2 || hours == 14)
        cout << "Two";
    if (hours == 3 || hours == 15)
        cout << "Three";
    if (hours == 4 || hours == 16)
        cout << "Four";
    if (hours == 5 || hours == 17)
        cout << "Five";
    if (hours == 6 || hours == 18)
        cout << "Six";
    if (hours == 7 || hours == 19)
        cout << "Seven";
    if (hours == 8 || hours == 20)
        cout << "Eight";
    if (hours == 9 || hours == 21)
        cout << "Nine";
    if (hours == 10 || hours == 22)
        cout << "Ten";
    if (hours == 11 || hours == 23)
        cout << "Eleven";
    if (hours == 12 || hours == 24)
        cout << "Twelve";
    
    //now for coverting the minutes into words
    //have to convert minutes into two digit number
    
    mfirst_digit = minutes / 10;
    msecond_digit = minutes % 10;
    
    while (minutes < 20)
    {
        if (minutes == 1)
            cout << " o' one";
        if (minutes == 2)
            cout << " o' two";
        if (minutes == 3)
            cout << " o' three";
        if (minutes == 4)
            cout << " o' four";
        if (minutes == 5)
            cout << " o' five";
        if (minutes == 6)
            cout << " o' six";
        if (minutes == 7)
            cout << " o' seven";
        if (minutes == 8)
            cout << " o' eight";
        if (minutes == 9)
            cout << " o' nine";
        if (minutes == 10)
            cout << " ten";
        if (minutes == 11)
            cout << " eleven";
        if (minutes == 12)
            cout << " twelve";
        if (minutes == 13)
            cout << " thirteen";
        if (minutes == 14)
            cout << " fourteen";
        if (minutes == 15)
            cout << " fifteen";
        if (minutes == 16)
            cout << " sixteen";
        if (minutes == 17)
            cout << " seventeen";
        if (minutes == 18)
            cout << " eighteen";
        if (minutes == 19)
            cout << " nineteen";
        break;
    }
    
    //numbers above the teens and singles
    if (mfirst_digit == 2)
        cout << " twenty";
    if (mfirst_digit == 3)
        cout << " thirty";
    if (mfirst_digit == 4)
        cout << " fourty";
    if (mfirst_digit == 5)
        cout << " fifty";

    //now for the singles for numbers > 20
    while (minutes > 20)
    {
        if (msecond_digit == 1)
            cout << "-one";
        if (msecond_digit == 2)
            cout << "-two";
        if (msecond_digit == 3)
            cout << "-three";
        if (msecond_digit == 4)
            cout << "-four";
        if (msecond_digit == 5)
            cout << "-five";
        if (msecond_digit == 6)
            cout << "-six";
        if (msecond_digit == 7)
            cout << "-seven";
        if (msecond_digit == 8)
            cout << "-eight";
        if (msecond_digit == 9)
            cout << "-nine";
        break;
    }
        
    //addding pm vs am to the time
    if (hours >= 12)
        cout << " P.M.";
        else
            cout << " A.M.";
    
    
    
    
    
    
    cout << endl << endl;
    
    return 0;
}
