//
//  chemestry.cpp
//  Practicum_13
//
//  Created by Jackson Warren on 11/15/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include "chemestry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include "chemestry.h"

using namespace std;

const int maxSize = 100;
int maxChem = 0;
string chemical[maxSize];

bool loadFile()
{
    string fileName;
    
    cout << "Input file name: ";
    cin >> fileName;
    
    ifstream ifs;
    ifs.open(fileName.c_str());
    
    if (!ifs.is_open())
    {
        cout << "\n\tERROR IN OPENING THE FILE.\n";
        exit(1);
    }
    
    //priming read
    getline(ifs, chemical[maxChem++]);
    
    while (!ifs.eof())
    {
        getline(ifs, chemical[maxChem++]);
    }
    
    ifs.close();
    
    return true;
}

bool display()
{
    //tester
    for (int i = 0; i < maxChem; i++)
        cout << "Chemical " << i + 1 << ": " << chemical[i] << endl;
    
    return true;
}

void atoms()
{
    int counter = 0;
    
    for (int i = 0; i < strlen(); i++)
    {
        if (isupper())
    }
}
