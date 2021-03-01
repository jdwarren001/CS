/**********************
 * 
 * Program 2 (Links)
 * Jackson Warren
 * 2/13/2020
 * 
 **********************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct nodetype
{
    int address;
    int id;
    string first;
    string last;
    string department;
    int salary;
    nodetype *link;
};

void insertlist(nodetype *head, nodetype *tail, int id, string first, string last, string department, int salary)
{
    nodetype *next, *prior, *knew;

    knew = new nodetype; 
    knew -> id = id;
    knew -> first = first;
    knew -> last = last;
    knew -> department = department;
    knew -> salary = salary;

    prior = head; 
    next = head -> link;
    while (next != tail && knew -> id > next -> id)
    {
        prior = next;
        next = next -> link;
    }

    prior -> link = knew; 
    knew -> link = next;
}

void readem(nodetype *head, nodetype *tail)
{
    ifstream inf("My School");

    int id;
    string first, last, department;
    int salary;

    while(!inf.eof())
    {
        inf >> id >> first >> last >> department >> salary;
        insertlist(head, tail, id, first, last, department, salary);
    }
}

void createlist(nodetype *&head, nodetype *&tail)
{
    head = new nodetype; 
    tail = new nodetype;
    head -> id = -1; 
    tail -> id = 9999;
    head -> link = tail;
    tail -> link = NULL; 
}

bool emptylist(nodetype *head, nodetype *tail)
{
    return head -> link == tail; 
}

void traverselist(ofstream &outf, nodetype *head, nodetype *tail)
{
    nodetype *current;

    if (!emptylist(head, tail))
    {
        outf << setw(32) << "My School" << endl << endl;

        outf << left << setw(4) << " ID" << setw(12) << "  First" << setw(15) << "Last"  
            <<setw(12) << "Department" << right 
            << setw(14) << right << "Salary" << endl;

        for(int i = 0; i < 57; i++)
            outf << "-";
        outf << endl;

        current = head -> link;
        while (current != tail)
        {
            outf << left << setw(6) << current -> id << setw(10) << current -> first << 
            setw(15) << current -> last << setw(12) << current -> department 
            << right << setw(14) << current -> salary << endl;
            current = current -> link; 
        }
    }
    else 
    {
        outf << "LIST EMPTY" << endl;
    }
}

void deletelist(nodetype *head, nodetype *tail, int id)
{
    nodetype *current, *prior, *next;
    prior = head;
    current = prior -> link;
    next = current -> link;
    while (next != tail && id > current -> id)
    {
        prior = current;
        current = next;
        next = next -> link;
    }
    prior -> link = next;


    if(current -> id == id)
    {
        prior -> link = next; 
        delete current;
    }
    else 
        cout << "NOTHING FOUND IN LIST. ERROR." << endl;
}





int main()
{
ofstream outf;
outf.open("Output.txt");
nodetype *head, *tail;

outf << endl;

createlist(head, tail);
readem(head, tail);
traverselist(outf, head, tail);

int id = 7676, salary = 50000;
string first = "Charles", last = "Darwin", department = "Biology";
insertlist(head, tail, id, first, last, department, salary);

id = 3966;
deletelist(head, tail, id);

outf << endl << endl;
traverselist(outf, head, tail);


return 1;
}