/*******************
 * 
 * Jackson Warren
 * Apple Assigment
 * 9/3/21
 * 
 *******************/

#include <iostream>
#include <ctime>

using namespace std;

/* 
NOTES 

Started with c++, then tried to switch this code to other programs.
Functions for digitization are very similar to that of what came from class.
Several boolean functions to test that the words have the correct correlating numbers are employed as well (All "rule" functions).

*/

void digi_eat(int eat, int &E1, int &A1, int &T1) {
    int rem = eat;
    E1 = rem/100;
    rem = rem%100;
    A1 = rem/10;
    T1 = rem%10;
}

void digi_that(int that, int &T2, int &H2, int &A2, int &T21) {
    int rem = that;
    T2 = rem/1000;
    rem = rem%1000;
    H2 = rem/100;
    rem = rem%100;
    A2 = rem/10;
    T21 = rem%10;
}

void digi_apple(int apple, int &A3, int &P3, int &P32, int &L3, int &E3) {
    int rem = apple;
    A3 = rem/10000;
    rem = rem%10000;
    P3 = rem/1000;
    rem = rem%1000;
    P32 = rem/100;
    rem = rem%100;
    L3 = rem/10;
    E3 = rem%10;
}

bool rule_eat(int &E1, int &A1, int &T1) {
    return E1 != A1 && E1 != T1 && A1 != T1;
}

bool rule_that(int &T2, int &H2, int &A2, int &T21) {
    return T2 == T21 && T2 != H2 && T2 != A2 && H2 != A2 && H2 != T21 && A2 != T21; 
}

bool rule_apple(int A3, int P3, int P32, int L3, int E3) {
    return A3 != P3 && A3 != P32 && A3 != L3 && A3 != E3 && P3 == P32 && P3 != L3 && P3 != E3 && L3 != E3;
}

bool con_eat_that(int T1, int T2, int T21, int A1, int A2) {
    return T1 == T2 && A1 == A2 && T1 == T21;
}

bool con_eat_that_apple(int apple, int A1, int A2, int A3, int E1, int E3) {
    return A1 == A3 && A2 == A3 && E1 == E3;
}


int main() {
    clock_t start;
    start = clock();

    int eat, that, apple;
    int E1, A1, T1;
    int T2, H2, A2, T21;
    int A3, P3, P32, L3, E3;

    for(int eat = 100; eat < 1000; eat++) {
        digi_eat(eat, E1, A1, T1);                        
        if(rule_eat(E1, A1, T1)) {                          
            for(int that = 1000; that < 10000; that++) {
                digi_that(that, T2, H2, A2, T21);         
                if(rule_that(T2, H2, A2, T21)) {           
                    if(con_eat_that(T1, T2, T21, A1, A2)) { 
                        apple = eat + that;
                        if(apple > 9999 && apple < 100000) {           
                            digi_apple(apple, A3, P3, P32, L3, E3);               
                            if(rule_apple(A3, P3, P32, L3, E3)) {                 
                                if(con_eat_that_apple(apple, A1, A2, A3, E1, E3)) { 
                                    cout << eat << " + " << that << " = " << apple << endl; 
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

// Results:
// 819 + 9219 = 10038
// Duration = 0.133219 seconds.