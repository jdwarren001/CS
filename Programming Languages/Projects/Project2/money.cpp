/*******************
 * 
 * Jackson Warren
 * Apple Assigment
 * 10/4/21
 * 
 *******************/

#include <iostream>
#include <ctime>

using namespace std;

/* 
NOTES 

*/

void digi_send(int send, int &S1, int &E1, int &N1, int &D1) {
    int rem = send;
    S1 = rem/1000;
    rem = rem%1000;
    E1 = rem/100;
    rem = rem%100;
    N1 = rem/10;
    D1 = rem%10;
}

void digi_more(int more, int &M21, int &O21, int &R21, int &E21) {
    int rem = more;
    M21 = rem/1000;
    rem = rem%1000;
    O21 = rem/100;
    rem = rem%100;
    R21 = rem/10;
    E21 = rem%10;
}

void digi_money(int money, int &M31, int &O31, int &N31, int &E31, int &Y31) {
    int rem = money;
    M31 = rem/10000;
    rem = rem%10000;
    O31 = rem/1000;
    rem = rem%1000;
    N31 = rem/100;
    rem = rem%100;
    E31 = rem/10;
    Y31 = rem%10;
}

bool rule_send(int S1, int E1, int N1, int D1) {
    return S1 != E1 && S1 != N1 && S1 != D1 && E1 != N1 && E1 != D1 && N1 != D1;
}

bool rule_more(int M21, int O21, int R21, int E21) {
    return M21 != O21 && M21 != R21 && M21 != E21 && O21 != R21 && O21 != E21 && R21 != E21; 
}

bool rule_money(int M31, int O31, int N31, int E31, int Y31) {
    return M31 != O31 && M31 != N31 && M31 != E31 && M31 != Y31 && O31 != N31 && O31 != E31 && O31 != Y31 && N31 != E31 && N31 != Y31 && E31 != Y31;
}

bool con_send_more(int E1, int E21) {
    return E1 == E21;
}

bool con_send_more_money(int E1, int E31, int M21, int M31, int O21, int O31, int N1, int N31, int R21, int Y31, int D1, int S1) {
    return E1 == E31 && M21 == M31 && O21 == O31 && N1 == N31 && R21 != N31 && R21 != Y31 && D1 != R21 && S1 != R21;
}


int main() {
    clock_t start;
    start = clock();

    int send, more, money;
    int S1, E1, N1, D1;
    int M21, O21, R21, E21;
    int M31, O31, N31, E31, Y31;
    int solutionNum = 1;

    for(int send = 1000; send < 10000; send++) {
        digi_send(send, S1, E1, N1, D1);                        
        if(rule_send(S1, E1, N1, D1)) {                          
            for(int more = 1000; more < 10000; more++) {
                digi_more(more, M21, O21, R21, E21);         
                if(rule_more(M21, O21, R21, E21)) {           
                    if(con_send_more(E1, E21)) { 
                        money = send + more;
                        if(money > 9999 && money < 100000) {           
                            digi_money(money, M31, O31, N31, E31, Y31);               
                            if(rule_money(M31, O31, N31, E31, Y31)) {                 
                                if(con_send_more_money(E1, E31, M21, M31, O21, O31, N1, N31, R21, Y31, D1, S1)) { 
                                    cout << solutionNum << ": " << send << " + " << more << " = " << money << endl; 
                                    solutionNum++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    double duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Duration = " << duration << " seconds.";
}
