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

void digi_cross(int cross, int &C1, int &R1, int &O1, int &S1, int &S2) {
    int rem = cross;
    C1 = rem/10000;
    rem = rem%10000;
    R1 = rem/1000;
    rem = rem%1000;
    O1 = rem/100;
    rem = rem%100;
    S1 = rem/10;
    S2 = rem%10;
}

void digi_roads(int roads, int &R21, int &O21, int &A21, int &D21, int &S21) {
    int rem = roads;
    R21 = rem/10000;
    rem = rem%10000;
    O21 = rem/1000;
    rem = rem%1000;
    A21 = rem/100;
    rem = rem%100;
    D21 = rem/10;
    S21 = rem%10;
}

void digi_danger(int danger, int &D31, int &A31, int &N31, int &G31, int &E31, int &R31) {
    int rem = danger;
    D31 = rem/100000;
    rem = rem%100000;
    A31 = rem/10000;
    rem = rem%10000;
    N31 = rem/1000;
    rem = rem%1000;
    G31 = rem/100;
    rem = rem%100;
    E31 = rem/10;
    R31 = rem%10;
}

bool rule_cross(int C1, int R1, int O1, int S1, int S2) {
    return C1 != R1 && C1 != O1 && C1 != S1 && C1 != S2 && R1 != O1 && R1 != S1 && R1 != S2 && O1 != S1 && O1 != S2 && S1 == S2;
}

bool rule_roads(int R21, int O21, int A21, int D21, int S21) {
    return R21 != O21 && R21 != A21 && R21 != D21 && R21 != S21 && O21 != A21 && O21 != D21 && O21 != S21 && A21 != D21 && A21 != S21 && D21 != S21; 
}

bool rule_danger(int D31, int A31, int N31, int G31, int E31, int R31) {
    return D31 != A31 && D31 != N31 && D31 != G31 && D31 != E31 && D31 != R31 && A31 != N31 && A31 != G31 && A31 != E31 && A31 != R31 && N31 != G31 && N31 != E31 && N31 != R31 && G31 != E31 && G31 != R31 && E31 != R31;
}

bool con_cross_roads(int R1, int R21, int O1, int O21, int S1, int S21) {
    return R1 == R21 && O1 == O21 && S1 == S21;
}

bool con_cross_roads_danger(int A21, int A31, int R1, int R31, int D21, int D31, int C1, int E31, int O21, int G31, int S1, int N31) {
    return A21 == A31 && R1 == R31 && D21 == D31 && C1 != E31 && O21 != E31 && O21 != G31 && S1 != N31 && C1 != N31;
}


int main() {
    clock_t start;
    start = clock();

    int cross, roads, danger;
    int C1, R1, O1, S1, S2;
    int R21, O21, A21, D21, S21;
    int D31, A31, N31, G31, E31, R31;
    int solutionNum = 1;

    for(int cross = 10000; cross < 100000; cross++) {
        digi_cross(cross, C1, R1, O1, S1, S2);                        
        if(rule_cross(C1, R1, O1, S1, S2)) {                          
            for(int roads = 10000; roads < 100000; roads++) {
                digi_roads(roads, R21, O21, A21, D21, S21);         
                if(rule_roads(R21, O21, A21, D21, S21)) {           
                    if(con_cross_roads(R1, R21, O1, O21, S1, S21)) { 
                        danger = cross + roads;
                        if(danger > 99999 && danger < 1000000) {            
                            digi_danger(danger, D31, A31, N31, G31, E31, R31);               
                            if(rule_danger(D31, A31, N31, G31, E31, R31)) {            
                                if(con_cross_roads_danger(A21, A31, R1, R31, D21, D31, C1, E31, O21, G31, S1, N31)) { 
                                    cout << solutionNum << ": " << cross << " + " << roads << " = " << danger << endl; 
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