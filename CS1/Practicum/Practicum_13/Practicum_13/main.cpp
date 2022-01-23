//
//  main.cpp
//  Practicum_13
//
//  Created by Jackson Warren on 11/15/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "chemestry.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    loadFile();
    display(); // comment out to stop displaying tester
    atoms();
    
    return 0;
}
