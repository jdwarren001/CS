#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

enum TokenType {BeginSym, EndSym, ReadSym, WriteSym, Id, IntLiteral, LParen,
RParen, SemiColon, Comma, AssignOp, PlusOp, MinusOp, EofSym, Blank, Comment, Error};

stack<int> paren;

TokenType checkReserved(string word){
    if(word == "BEGIN"){
        cout << word << endl;
        return BeginSym;
    }
    else if(word == "END"){
        cout << word << endl;
        return EndSym;
    }
    else if(word == "READ"){
        cout << word << endl;
        return BeginSym;
    }
    else if(word == "WRITE"){
        cout << word << endl;
        return WriteSym;
    }
    else {
        cout << "ID = " << word << endl;
        return Id;
    }
}

string BufferChar(char currentChar, string &TokenBuffer){
    return TokenBuffer += currentChar;
}

string ClearBuffer(string &TokenBuffer){
    return TokenBuffer = "";
}

TokenType scanner(ifstream &ifs){
    char currentChar = ' ';
    char nextChar = ' ';
    string trash = "";
    string TokenBuffer = "";

    ifs.get(currentChar);

    ClearBuffer(TokenBuffer);

    if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n'){
        return Blank;
    }


    else if(isalpha(currentChar)) {
        BufferChar(currentChar, TokenBuffer);
        while(isalnum(ifs.peek()) || ifs.peek() == '_') {
            ifs.get(currentChar);
            BufferChar(currentChar, TokenBuffer);
        }
        return checkReserved(TokenBuffer);
    }

    else if(isdigit(currentChar)){
        BufferChar(currentChar, TokenBuffer);
        while(isdigit(ifs.peek())){
            ifs.get(currentChar);
            BufferChar(currentChar, TokenBuffer);
        }
        cout << "Number: " << TokenBuffer << endl;
        return IntLiteral;
    }

    else if(currentChar == '('){
        cout << "Lparen" << endl;
        paren.push(currentChar);
        return LParen;
    }

    else if(currentChar == ')'){
        cout << "Rparen" << endl;
        paren.pop();
        return RParen;
    }

    else if(currentChar == ';') {
        cout << "SemiColon" << endl;
        return SemiColon;
    }

    else if(currentChar == ',') {
        cout << "Comma" << endl;
        return Comma;
    }

    else if(currentChar == '+') {
        cout << "PlusOp" << endl;
        return PlusOp;
    }

    else if(currentChar == ':'){
        if(ifs.peek() == '='){
            ifs.get(currentChar);
            cout << "AssignOp" << endl;
            return AssignOp;
        }
        else{
            cout << "Lexical Error " << currentChar << endl;
        }
    }

    else if(currentChar == '-'){
        if(ifs.peek() == '-'){
            getline(ifs, trash);
            cout << "Comment: " << currentChar + trash << endl;
            return Comment;
        }
        else cout << "MinusOp" << endl;
        return MinusOp;
    }

    else{
        if(!paren.empty()) cout << "Lexical Error, missing parenthases. " << endl;
        cout << "Lexical Error " << currentChar << endl;
        exit(1);
    }
    return Error;
}

int main(){
    ifstream ifs;
    ifs.open("input.txt");
    while(!ifs.eof()){
        scanner(ifs);
    }
    ifs.close();
    cout << "EofSym" << endl;
    return EofSym;

    return 0;
}