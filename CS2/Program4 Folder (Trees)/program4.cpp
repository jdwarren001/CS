/******************
 * 
 * Jackson Warren
 * 3/13/20
 * Binary Search Tree (BST)
 * 
 ******************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct treetype
{
    int id;
    treetype *left, *right;
};

void createtree(treetype *&root)
{
    root = new treetype;
    root -> id = -1;
    root -> left = NULL;
    root -> right = NULL;
}

bool emptytree(treetype *root)
{
    return root -> id == -1;
}

void inserttree(treetype *&root, int id)
{
    treetype *knew, *parent, *c;

    knew = new treetype;
    knew -> id = id;
    knew -> left = NULL;
    knew -> right = NULL;

    if(!emptytree(root))
    {
        parent = NULL;
        c = root;

        while(c != NULL)
        {
            parent = c;
            if(id < c -> id)
                c = c -> left;
            else if(id > c -> id)
                c = c -> right;
        }
        if(id < parent -> id)
            parent -> left = knew;
        else if(id > parent -> id)
            parent -> right = knew;
    }
    else
        root -> id = id;
    
}

void readem(treetype *&root)
{
    int id = 0;
    ifstream ifs("Input.txt");

    while(!ifs.eof())
    {
        ifs >> id;
        inserttree(root, id);
    }
}

void deleteleaf(treetype *c, treetype *parent)
{
    if(c -> id < parent -> id)
        parent -> left = NULL;
    else
        parent -> right = NULL;
    delete c;
    
}

void deleteone(treetype *c, treetype *parent)
{
    treetype *child;
    if(c -> left != NULL)
        child = c -> left;
    else
        child = c -> right;

    if(c -> id < parent -> id)
        parent -> left = child;
    else
        parent -> right = child;

    delete c;
}

void deletetwo(treetype *c)
{
    treetype *replace, *pofreplace;

    pofreplace = c;
    replace = c -> left;

    while(replace -> right != NULL)
    {
        pofreplace = replace;
        replace = replace -> right;
    }

    c -> id = replace -> id;
    if(replace -> left != NULL)
        deleteone(replace, pofreplace);
    else
        deleteleaf(replace, pofreplace);
}

void deletetree(treetype *root, int id)
{
    treetype *c, *parent;

    parent = NULL;
    c = root;

    while(c != NULL && id != c -> id)
    {
        parent = c;
        if(id < c -> id)
            c = c -> left;
        else 
            c = c -> right;
    }
    if(c != NULL)
    {
        if(c -> left == NULL && c -> right == NULL)
            deleteleaf(c, parent);
        if(c -> left != NULL && c -> right != NULL)
            deletetwo(c);
        else
            deleteone(c, parent);
    }
    else
        cout << "ERROR. Could not delete desired item." << endl;
}

void preorder(treetype *c, ofstream &ofs)
{
    ofs << c -> id << " ";
    if(c -> left != NULL)
        preorder(c -> left, ofs);
    if(c -> right != NULL)
        preorder(c -> right, ofs);
}

void inorder(treetype *c, ofstream &ofs)
{
    if(c -> left != NULL)
        inorder(c -> left, ofs);
    ofs << c -> id << " ";
    if(c -> right != NULL)
        inorder(c -> right, ofs);
}

void postorder(treetype *c, ofstream &ofs)
{
    if(c -> left != NULL)
        postorder(c -> left, ofs);
    if(c -> right != NULL)
        postorder(c -> right, ofs);
    ofs << c -> id << " ";
}


treetype* initrec = NULL;
const int maxstack = 20;

void createstack(treetype* stack[], int &top)
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

treetype* pop(treetype* stack[], int &top)
{
    treetype* answer = 0;

    if(!emptystack(top))
    {
        answer = stack[top];
        stack[top] = initrec;
        top--;
    }
    return answer;
}

void push(treetype* stack[], int &top, treetype* num)
{
    if(!fullstack(top))
    {
        top++;
        stack[top] = num;
    }
    else 
        cout << "Stack is FULL." << endl;
}

void iterativepre(ofstream &ofs, treetype *root, treetype* stack[], int top)
{
    treetype *c;
    c = root;
    push(stack, top, NULL);

    while(c != NULL)
    {
        ofs << c -> id << " ";
        if(c -> right != NULL)
            push(stack, top, c -> right);
        if(c -> left != NULL)
            c = c -> left;
        else
            c = pop(stack, top); 
    }
}

void iterativein(ofstream &ofs, treetype *root, treetype* stack[], int top)
{
    treetype *c;
    push(stack, top, NULL);
    c = root;

    while(c != NULL)
    {
        while(c -> left != NULL)
        {
            push(stack, top, c);
            c = c -> left;
        }

        bool done = false;
        while(done == false)
        {
            ofs << c -> id << " ";
            if(c -> right != NULL)
            {
                c = c -> right;
                done = true;
            }
            else
                c = pop(stack, top);
            if(c == NULL)
                done = true;
        }
    }
}


int main()
{
    ofstream ofs("Output.txt");
    treetype* stack[maxstack];
    int top = 0;
    treetype *root, *c;

    createtree(root);
    readem(root);

    ofs << setw(35) << "Binary Search Tree" << endl;
    for(int i = 0; i < 53; i++)
        ofs << '-';

    ofs << endl << "InOrder (Recursive): " << endl << '\t';
    inorder(root, ofs);
        ofs << endl;

    int id = 71;
    deletetree(root, id);
    ofs << "PostOrder (Recursive, delete 71): " << endl << '\t';
    postorder(root, ofs);
        ofs << endl;

    id = 38;
    deletetree(root, id);
    ofs << "PreOrder (Recursive, delete 38-left subtree-): " << endl << '\t';
    preorder(root, ofs);
        ofs << endl;

    createstack(stack, top);
    ofs << "PreOrder (Iterative): " << endl << '\t';
    iterativepre(ofs, root, stack, top);
        ofs << endl;

    ofs << "InOrder (Iterative): " << endl << '\t';
    iterativein(ofs, root, stack, top);
    ofs << endl;

    return 0;
}