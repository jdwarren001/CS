//
//  chemestry.hpp
//  Practicum_13
//
//  Created by Jackson Warren on 11/15/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#ifndef chemestry_h
#define chemestry_h

#include <stdio.h>
#include <iostream>

using namespace std;

struct orginizer
{
    string *element;
};

bool loadFile();
bool display();
void atoms();

#endif /* chemestry_h */
