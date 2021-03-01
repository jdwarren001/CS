/*********************
 * 
 * Program 3 (Stacks and Converting to RPN)
 * Jackson Warren
 * 3/3/2020
 * 
 ********************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char initrec = ' ';
const int maxstack = 20;

void createstack(char stack[], int &top)
{
    top = -1;

    for(int i = 0; i < maxstack; i++)
    {
     stack[i] = initrec;
    }
}

bool fullstack(int top)
{
    return top >= maxstack - 1;
}

bool emptystack(int top)
{
    return top < 0;
}

char pop(char stack[], int &top)
{
    char answer = ' ';

    if(!emptystack(top))
    {
        answer = stack[top];
        stack[top] = initrec;
        top--;
    }
    return answer;
}

void push(char stack[], int &top, char num)
{
    if(!fullstack(top))
    {
        top++;
        stack[top] = num;
    }
    else 
        cout << "Stack is FULL." << endl;
}

int priority(char ch)
{
    int temp = 0;

    switch(ch)
    {
        case '+':
            temp = 1;
            break;
        case '-':
            temp = 1;
            break;
        case '*':
            temp = 2;
            break;
        case '/':
            temp = 2;
            break;
    }
    return temp;
}

void converter(char stack[], int &top)
{
    ifstream ifs("Input.txt");
    ofstream ofs("Output.txt");
    string instring = " ", outstring = " ";
    int len;
    char ch = ' ';

    ofs << setw(17) << "RPN Form" << endl;
    ofs << left << setw(15) << "Input String" <<  setw(15) << "Output String" << endl;
    for(int i = 0; i < 28; i++)
        ofs << "-";

    while(!ifs.eof())
    {
        ifs >> instring;
        outstring.clear();
        len = instring.length();
        for(int i = 0; i < len; i++)
        {
            ch = instring[i];
            
            if(ch >= 'A' && ch <= 'Z')
                outstring += ch;
            else if(ch == '(')
                push(stack, top, ch);
            else if(ch == ')')
            {
                while(stack[top] != '('){
                    outstring += pop(stack, top);}
                ch = pop(stack, top);
            }
            else if(emptystack(top))
                push(stack, top, ch);
            else if(priority(ch) > priority(stack[top]))
                push(stack, top, ch);
            else 
            {
                while(!emptystack(top) && priority(ch) <= priority(stack[top])){
                    outstring += pop(stack, top);}
                push(stack, top, ch);
            }
        }
        while(!emptystack(top))
            outstring += pop(stack, top);
        ofs << endl << left << setw(15) << instring << setw(15) << outstring << endl;
    }
}



int main()
{
    char stack[maxstack];
    int top;

    createstack(stack, top);
    converter(stack, top);

    return 0;
}