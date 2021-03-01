/**********************
 * 
 * Extra Credit #1
 * Jackson Warren
 * 2/13/20
 * 
 **********************/

//Program uses list of arrays similar to that of a dynamic list. 


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int maxlist = 50;

struct listtype
{
    int id;
    string first;
    string last;
    string department;
    int salary;
};

listtype initrec[maxlist] = {0, " ", " ", " ", 0};

bool fulllist(int numlist)
{
    return maxlist <= numlist;
}

void insertlist(listtype list[], int &numlist, int id, string first, string last, string department, int salary)
{
    if(!fulllist(numlist))
    {
        int where = 0;

        while(where < numlist && id > list[where].id) 
        {
            where++;
        }

        for(int i = numlist; i >= where; i--)
        {
            list[i+1] = list[i];
        }
        list[where].id = id;
        list[where].first = first;
        list[where].last = last;
        list[where].department = department;
        list[where].salary = salary;
        numlist++;
    }
}

void createlist(int &numlist, listtype list[])
{
    ifstream ifs("Marvel College");

    for(int i = 0; i < maxlist; i++)
    {
        list[i] = initrec[i];
    }

    int id, salary;
    string first, last, department;

    while(!ifs.eof())
    {
        ifs >> id >> first >> last >> department >> salary;
        insertlist(list, numlist, id, first, last, department, salary);
    }
}

void deletelist(int &numlist, listtype list[],int id)
{
    int where = 0;

    while(where < numlist && id > list[where].id)
    {
        where++;
    }
    if(list[where].id == id)
    {
        for(int i = where; i < numlist - 1; i++)
        {
            list[i] = list[i + 1];
        }
        list[numlist - 1] = initrec[numlist - 1];
        numlist--;
    }
}

bool emptylist(int numlist)
{
    return numlist < 1;
}

void traverselist(int numlist, listtype list[], ofstream &ofs)
{
    ofs << setw(32) << "Marvel College" << endl << endl;

    ofs << left << setw(4) << " ID" << setw(12) << "  First" << setw(15) << "Last"  
        <<setw(12) << "Department" << right 
        << setw(14) << right << "Salary" << endl;

    for(int i = 0; i < 57; i++)
        ofs << "-";

    ofs << endl;

    for(int i = 0; i < numlist; i++)
    {
        ofs << left << setw(6) << list[i].id << setw(10) << list[i].first 
        << setw(15) << list[i].last << setw(12) << list[i].department 
        << right << setw(14) << list[i].salary << endl;
    }
}



int main()
{
    int numlist = 0;
    ofstream ofs("Output.txt");
    listtype list[maxlist];

    createlist(numlist, list);
    traverselist(numlist, list, ofs);

    int id = 7676, salary = 50000;
    string first = "Charles", last = "Darwin", department = "Biology";
    insertlist(list, numlist, id, first, last, department, salary);

    id = 3966;
    deletelist(numlist, list, id);

    ofs << endl << endl;
    traverselist(numlist, list, ofs);

    return 0;
}