//
//  task3.cpp
//  Practicum_11
//
//  Created by Jackson Warren on 10/29/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

struct bookInfo
{
    char title[50];
    char author[30];
    double price;
};

void bookPrint(bookInfo);

void bookPrint(bookInfo bookTemp)
{
    cout << "Title: " << bookTemp.title << endl << "Author: " << bookTemp.author << endl << "Cost: " << bookTemp.price << endl << endl;
}

int main(int argc, const char * argv[]) {
    
    bookInfo myBook1 = {};
    string temp = "Digital Fortress";
    
    myBook1 = {"Da Vinci Code", "Dan Brown", 24.20}; //declaration all in one
    //myBook1.title = "Da Vinci Code" -> declaration one by one
    
    bookPrint(myBook1);
    
    
    bookInfo myBook2 = {};
    strcpy(myBook2.title, myBook1.title);
    strcpy(myBook2.title, temp.c_str());
    strcpy(myBook2.author, myBook1.author);
    myBook2.price = myBook1.price;
    myBook2.price = 14.78;
    
    bookPrint(myBook2);
    
    return 0;
}
