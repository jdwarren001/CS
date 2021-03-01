/**********************
 * 
 * Jackson Warren
 * Program 6, Sort Functions
 * TBD
 * 
 ***********************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int n = 10000;
int swaps = 0;
int compare = 0;

void initem(int num[])
{
    for(int i = 0; i < n; i++)
        num[i] = -1;
}

void readem(int num[])
{
    ifstream ifs("Input.txt");
    int input;

    for(int i = 0; i < n; i++)
    {
        ifs >> input;
        num[i] = input;
    }
}

void swapem(int &num1, int &num2)
{
    int temp = num1;

    num1 = num2;
    num2 = temp;

    swaps += 3;
}

void bubblesort(int num[])
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1; j++)
        {
            compare++;
            if(num[j] > num[j + 1])
            {
                swapem(num[j], num[j + 1]);
            }
        }
}

void ibs(int num[])
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1 - i; j++)
        {
            compare++;
            if(num[j] > num[j + 1])
            {
                swapem(num[j], num[j + 1]);
            }
        }
}

void ss(int num[])
{
    int j, k, small;

    if(n > 0)
    {
        for(k = 0; k < n - 1; k++)
        {
            small = k;
            for(j = k + 1; j < n; j++)
            {
                compare++;
                if(num[j] < num[small])
                    small = j;
            }
            if(k < small)
                swapem(num[k], num[small]);
        }
    }
}

void is(int num[])
{
    int j = 0, k = 0, save = 0;

    for(k = n - 2; k >= 0; k--)
    {
        j = k + 1;

        save = num[k];
        num[n] = save;
        swaps += 2;

        while(save > num[j])
        {
            num[j - 1] = num[j];
            swaps++;
            compare++;
            j = j + 1;
        }
        compare++;

        num[j - 1] = save;
        swaps++;
    }
}

void qs(int num[], int left, int right)
{
    int j = 0, k = 0;

    if(left < right)
    {
        j = left;
        k = right + 1;

        do 
        {
            do 
            {
                j = j + 1;
                compare++;
            } 
            while(num[j] <= num[left] && j < k);

            do 
            {
                k = k - 1;
                compare++;
            } 
            while(num[k] >= num[left] && k >= 0);

            if(j < k)
                swapem(num[j], num[k]);
        } 
        while(j < k);

        swapem(num[left], num[k]);

        qs(num, left, k - 1);
        qs(num, k + 1, right);
    }
}

void printarray(ofstream &ofs, int num[], string str)
{
    ofs << str << " ";
    /*
    for(int i = 0; i < n; i++)
        ofs << num[i] << " "; */
    ofs << endl;
    ofs << "Comparisons done: " << compare << endl;
    ofs << "Swaps done: " << swaps << endl << endl;
}

int main()
{
    ofstream ofs("Output.txt");
    int num[n + 1];
    string str = " ";
    int numsorts = 5;

    int left = 0, right = 0;

    initem(num);
    readem(num);
    ofs << "n = " << n << endl << endl;
    printarray(ofs, num, "Unsorted Array: ");

    for(int i = 0; i < numsorts; i++)
    {
        readem(num);
        swaps = 0; 
        compare = 0;
        switch (i)
        {
            case 0: bubblesort(num);
                str = "BubbleSort: ";
                break;
            case 1: ibs(num);
                str = "Improved BubbleSort: ";
                break;
            case 2: ss(num);
                str = "Select Sort: ";
                break;
            case 3: is(num);
                str = "InsertSort: ";
                break;
            case 4: qs(num, 0, n - 1);
                str = "QuickSort: ";
                break;
        }
        printarray(ofs, num, str);
    }

    return 0;
}