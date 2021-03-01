/*********************
 * 
 * Jackson Warren
 * Program 1 (Chars and Bools)
 * 9/29/20
 * 
*********************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int maxset = 'Z' + 1;

void init(bool universalSet[], bool vowel[], bool myName[]) {
    char ch;
    ifstream ifs("input.txt");
    
    for (ch = 'A'; ch <= 'Z'; ch++) {
        universalSet[ch] = true;
    }

    vowel['A'] = true;
    vowel['E'] = true;
    vowel['I'] = true;
    vowel['O'] = true;
    vowel['U'] = true;

    while(!ifs.eof()) {
        ifs >> ch;
        myName[ch] = true;
    }

    ifs.close();

}

void setFalse(bool set[]) {
    char ch;

    for (ch = 'A'; ch <= 'Z'; ch++) {
        set[ch] = false;
    }

}

void print(ofstream &ofs, bool s[], string name) {
    int i;

    ofs << "Set " << name << endl;
    for(i = 'A'; i <= 'Z'; i++) {
        if(s[i] == true)
            ofs << setw(2) << (char)i;
        else 
            ofs << setw(2) << ' ';
    }

    ofs << endl << endl;
}

void printEqual(ofstream &ofs, bool s[], bool s2[], string name, string name2) {
    int i;
    ofs << endl << endl << "Set " << name << endl;
    for(i = 'A'; i <= 'Z'; i++) {
        if(s[i] == true)
            ofs << setw(2) << (char)i;
        else 
            ofs << setw(2) << ' ';
    }

    ofs << endl << endl << "Set " << name2 << endl;
    for(i = 'A'; i <= 'Z'; i++) {
        if(s2[i] == true)
            ofs << setw(2) << (char)i;
        else 
            ofs << setw(2) << ' ';
    }

    ofs << endl << endl << endl;
}

void unionTest(bool s[], bool s2[], bool unionSet[]) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(s[i] == true || s2[i] == true)
            unionSet[i] = true; 
    }
}

void intersectTest(bool s[], bool s2[], bool intersectSet[]) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(s[i] == true && s2[i] == true)
            intersectSet[i] = true; 
    }
}

void differenceTest(bool s[], bool s2[], bool differenceSet[]) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(s[i] == true && s2[i] != true)
            differenceSet[i] = true; 
        else 
            differenceSet[i] = false; 
    }
}

bool equalTest(bool s[], bool s2[]) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(s[i] != s2[i])
            return false;
    }
    return true;
}

void equalDisplay(ofstream &ofs, bool result, bool s[], bool s2[], string set1, string set2) {
    if(result == true) {
        ofs << "=>Elements in " << set1 << " Set and " << set2 << " Set are equal sets." << endl;
        print(ofs, s, "elements are equal sets: ");
    }
    else {
        ofs << "=>Elements in " << set1 << " Set and " << set2 << "Set are not equal sets!" << endl;
        print(ofs, s, set1);
        print(ofs, s2, set2);
    }
}


bool subsetTest(bool s[], bool s2[]) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(s2[i] && !s[i])
            return false;
    }
    return true;
}

void subsetDisplay(ofstream &ofs, bool result, bool s[], bool s2[], string set1, string set2) {
    if(result == true){
        ofs << "=>Elements in " << set1 << " Set are a subset of " << set2 << " Set." << endl;
        print(ofs, s, set1);
        print(ofs, s2, set2);
    }
    else {
        ofs << "=>Elements in Vowel Set are not a subset of My Name Set!" << endl;
        print(ofs, s, set1);
        print(ofs, s2, set2);
    }
}


int main() {
    ofstream ofs("output.txt");

    bool universalSet[maxset];
    bool vowel[maxset];
    bool myName[maxset];
    bool unionSet[maxset];
    bool intersectSet[maxset];
    bool differenceSet[maxset];

    setFalse(universalSet);
    setFalse(vowel);
    setFalse(myName);
    setFalse(unionSet);
    setFalse(intersectSet);
    setFalse(differenceSet);

    init(universalSet, vowel, myName);

    print(ofs, universalSet, "Universal: ");
    print(ofs, vowel, "Vowel: ");
    print(ofs, myName, "My Name: ");

    ofs << "_________________________________________________________" << endl;
    ofs << endl << endl;

    unionTest(vowel, myName, unionSet);
    print(ofs, unionSet, "elements in Union between Vowel Set and My Name Set: ");

    intersectTest(vowel, myName, intersectSet);
    print(ofs, intersectSet, "elements in Intersection between Vowel Set and My Name Set: ");

    differenceTest(myName, vowel, differenceSet);
    print(ofs, differenceSet, "elements in the Difference from My Name Set to Vowel Set: ");

    ofs << "_________________________________________________________" << endl;
    ofs << endl << endl;

    bool result;
    result = equalTest(myName, vowel);
    equalDisplay(ofs, result, vowel, myName, "Vowel", "My Name");

    result = equalTest(vowel, vowel);
    equalDisplay(ofs, result, vowel, vowel, "Vowel", "Vowel");

    ofs << "_________________________________________________________" << endl;
    ofs << endl << endl;

    result = subsetTest(myName, vowel);
    subsetDisplay(ofs, result, vowel, myName, "Vowel", "My Name");

    result = subsetTest(universalSet, vowel);
    subsetDisplay(ofs, result, vowel, universalSet, "Vowel", "Universal");

    
    


    return 0;
}