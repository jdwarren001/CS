/**************************
 * Jackson Warren
 * Doubly Linked Lists
 * 10/13/20
 *************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct nodetype
{
    int id;
    string name;
    nodetype *linknum;
    nodetype *linkname;
};

void insertlist(nodetype *head, nodetype *tail, int id, string name)
{
    nodetype *next, *prior, *knew;

    knew = new nodetype; 
    knew -> id = id;
    knew -> name = name;

    prior = head; 
    next = head -> linknum;
    while (next != tail && knew -> id > next -> id)
    {
        prior = next;
        next = next -> linknum;
    }
    prior -> linknum = knew; 
    knew -> linknum = next;

    prior = head; 
    next = head -> linkname;
    while (next != tail && knew -> name > next -> name)
    {
        prior = next;
        next = next -> linkname;
    }
    prior -> linkname = knew; 
    knew -> linkname = next;
}

void readem(nodetype *head, nodetype *tail)
{
    ifstream inf("input.txt");

    int id;
    string name;

    while(!inf.eof())
    {
        inf >> id >> name;
        insertlist(head, tail, id, name);
    }

    inf.close();
}

void createlist(nodetype *&head, nodetype *&tail)
{
    head = new nodetype; 
    tail = new nodetype;

    head -> id = -1; 
    tail -> id = 9999;
    head -> name = 'A' - 1;
    tail -> name = 'z' + 1;

    head -> linknum = tail;
    tail -> linknum = NULL; 
    head -> linkname = tail;
    tail -> linkname = NULL;
}

bool emptylist(nodetype *head, nodetype *tail)
{
    return head -> linknum == tail || head -> linkname == tail; 
}

void traverseListName(ofstream &outf, nodetype *head, nodetype *tail)
{
    nodetype *current;

    if (!emptylist(head, tail))
    {
        outf << endl << endl << "Ordered By Name: " << endl << endl;
        outf << left << setw(4) << " ID" << setw(12) << "  Name" << endl;

        for(int i = 0; i < 20; i++)
            outf << "-";
        outf << endl;

        current = head -> linkname;
        while (current != tail)
        {
            outf << left << setw(6) << current -> id << setw(10) << current -> name << endl;
            current = current -> linkname; 
        }
    }
    else 
    {
        outf << "LIST EMPTY" << endl;
    }
}

void traverseListNum(ofstream &outf, nodetype *head, nodetype *tail)
{
    nodetype *current;

    if (!emptylist(head, tail))
    {
        outf << endl << endl << "Ordered By ID: " << endl << endl;
        outf << left << setw(4) << " ID" << setw(12) << "  Name" << endl;

        for(int i = 0; i < 20; i++)
            outf << "-";
        outf << endl;

        current = head -> linknum;
        while (current != tail)
        {
            outf << left << setw(6) << current -> id << setw(10) << current -> name << endl;
            current = current -> linknum; 
        }
    }
    else 
    {
        outf << "LIST EMPTY" << endl;
    }
}

void deletelist(nodetype *head, nodetype *tail, int id, string name)
{
    nodetype *current, *prior, *next;

    prior = head;
    current = prior -> linknum;
    next = current -> linknum;
    while (next != tail && id > current -> id)
    {
        prior = current;
        current = next;
        next = next -> linknum;
    }

    if(current -> id == id && current -> name == name)
        prior -> linknum = next; 

    prior = head;
    current = prior -> linkname;
    next = current -> linkname;
    while (next != tail && id != current -> id)
    {
        prior = current;
        current = next;
        next = next -> linkname;
    }

    if(current -> id == id && current -> name == name)
    {
        prior -> linkname = next;
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

    outf << "Doubly Linked List:";

    traverseListName(outf, head, tail);
    traverseListNum(outf, head, tail);

    outf << endl << endl << "Solo deleted: ";
    deletelist(head, tail, 7234, "Solo");
    traverseListNum(outf, head, tail);

    outf << endl << endl << "Payne Added: ";
    insertlist(head, tail, 4020, "Payne");
    traverseListName(outf, head, tail);


    return 0;
}