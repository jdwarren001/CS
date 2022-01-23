//
//  task1.cpp
//  Practicum_7
//
//  Created by Jackson Warren on 10/1/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int salesPersonList[6];
double saleByQuarter[4];
const int numSalesMen = 6;


int QT1 = 0, QT2 = 0, QT3 = 0, QT4 = 0;


struct salesPerson
{
    int personId;
    double saleByQuarter[4] = {QT1, QT2, QT3, QT4};
    double annualSales;
};

void getData(ifstream&, salesPerson salesPersonList[numSalesMen], int);
void calculateSalesByMan (salesPerson salesPersonList[numSalesMen], int);
void calculateTotalSales (salesPerson salesPersonList[numSalesMen], int);
void printResult (ofstream&, const salesPerson salesPersonList[numSalesMen],
int);

int main(int argc, const char * argv[]) {

    
    ifstream inData;
    ofstream outData;
    salesPerson salesPersonList[numSalesMen];

    inData.open("Week7Data.txt");
    if (!inData)
    {
        cout << "The input file does not exist. Program terminates!"
             << endl;
        return 1;
    }

    outData.open("Week7DataOut.txt");
    if (!outData)
    {
        cout << "Cannot open the output file. Program terminates!"
             << endl;
        return 1;
    }


void getData (ifstream&, salesPerson salesPersonList[numSalesMen], int)
{
    
}
    
void calculateSalesByMan (salesPerson salesPersonList[numSalesMen], int)
{
    
}

void calculateTotalSales (salesPerson salesPersonList[numSalesMen], int)
{
    
}

void printResult (ofstream&, const salesPerson salesPersonList[numSalesMen],
int)
{
    int maxScore = highestScore(sList, listSize);
    int i;

    outFile << setw(15) << "Employee Name           "
            << setw(10) << "Employee Sales"

    for (i = 1; i < listSize; i++)
        outFile << left << setw(25)
                << sList[i].studentLName + ", " + sList[i].studentFName
                << right << " " << setw(5) << sList[i].testScore
                << setw(6) << " " << sList[i].grade << endl;

    outFile << endl << "Highest Test Score: " << maxScore << endl;
    outFile << "Students having the highest test score:" << endl;

    for (i = 1; i < listSize; i++)
        if (sList[i].testScore == maxScore)
            outFile << sList[i].studentLName + ",  " + sList[i].studentFName
                    << endl;
}
