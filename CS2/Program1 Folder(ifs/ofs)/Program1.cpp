/**************************

Program 1
Jackson Warren 
2/4/20

**************************/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int maxp = 150;
const int maxquan = 4;

struct ptype
{
    int id;
    string product;
    int quan[maxquan]; // stores quanity sold
    int tquan; // total quanitity
    double uprice; // unit price
    double sold; // amount sold
};


const struct ptype initrec = {-1, "Description", 0, 0, 0, 0, 0.0, 0.0, 0.0};

void initem(ptype sales[])
{
    for (int i = 0; i < maxp; i++) // initilization of array of structs
    {
        sales[i] = initrec;
    }
}

void readem(int &nump, ptype sales[])
{
    ifstream inf("My Little Store");
    int i = 0;

    while (!inf.eof()) //reads file and puts into struct array
    {
        inf >> sales[i].id >> sales[i].product >> sales[i].uprice;

        for (int j = 0; j < maxquan; j++)
        {
            inf >> sales[i].quan[j];
        }
        i++;
    }
    nump = i; //calculates the number of products in list
}

void calc(int nump, ptype sales[])
{
    int temp = 0, temp2 = 0;

    for (int i = 0; i < nump; i++)
    {
        for (int j = 0; j < maxquan; j++)
        {
            temp = sales[i].quan[j];
            temp2 += temp;
        }
        sales[i].tquan = temp2;
    }

    for (int i = 0; i < nump; i++)
    {
        sales[i].sold = temp2 * sales[i].uprice;
    }
    temp = 0;
    temp2 = 0;
}

void sort(int nump, ptype sales[])
{
    int temp = 0, temp2 = 0;

    for (int i = 0; i < nump; i++)
    {
        temp = sales[i].id;
        temp2 = sales[i + 1].id;
        if (temp < temp2)
        {
            swap(sales[i], sales[i + 1]);
            i -= i;
        }
        if (sales[i].id < sales[i + 1].id) //second loop is for the first ID (kept getting left behind)
            {
                swap(sales[i], sales[i +1]);
            }
    }
}

void print(int nump, ptype sales[], ofstream &outf)
{
    outf << setw(40) << "My Little Store" << endl;
    outf << setw(26);
    for (int i = 0; i < 15; i++)
    {
        outf << "-";
    }
    outf << endl;
    outf << setw(55) << "Total" << endl 
        << left << setw(5) << " ID" << setw(17) << "Description" << setw(10) << "Price" << setw(18) << "Weekly Sales"
        << setw(12) << "Units" << setw(12) << "Sales" << endl;
    for (int i = 0; i < 67; i++)
    {
        outf << "-";
    }
    outf << endl;
    for (int i = 0; i < nump; i++)
    {
        outf << left << setw(5) << sales[i].id  << setw(12) << sales[i].product << right << setw(10) << sales[i].uprice << '\t'; 
        for (int j = 0; j < maxquan; j++)
        {
            outf << setw(3) << sales[i].quan[j] << " ";
        } 
        outf << setw(9) << sales[i].tquan << setw(12) << sales[i].sold << endl;
    }
}

void search(int nump, ptype sales[], ofstream &outf, string item)
{
    outf << endl << "Search (Captial Required): " << item;
    for (int i = 0; i < nump; i++)
    {
        if (item == sales[i].product)
        {
            outf << endl;
            outf << "ID: " << sales[i].id << endl << "Units sold: " << sales[i].tquan << endl << "Sales: " << sales[i].sold << endl;
        }
    }
}




int main()
{
    ptype sales[maxp];
    int nump;
    ofstream outf;
    outf.open("Output.txt");
    outf.setf(ios::fixed);
    outf.precision(2);
    
    outf << endl;

    initem(sales);
    readem(nump, sales);
    calc(nump, sales);
    sort(nump, sales);
    print(nump, sales, outf);
    search(nump, sales, outf, "Coffee");


    return 0;
    
}
