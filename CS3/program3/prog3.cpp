/*************************
 * 
 * Jackson Warren
 * 10/23/20
 * MST
 * 
 ************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


const int maxVert = 'M' + 1;
enum colorType {white, grey, black};

struct edgeType {
    char v1, v2;
    int wt;
};

struct Qtype {
    char v1, v2;
    int wt;
    Qtype *link;
};

void init1(edgeType a[]) {
    for(int i = 'A'; i < maxVert; i++) {
        a[i].v1 = '?';
        a[i].v2 = '?';
        a[i].wt = 0;
    }
}

void init2(int a[][maxVert]) {
    for(int i = 'A'; i < maxVert; i++)
        for(int j = 'A'; j < maxVert; j++)
            a[i][j] = 0;
}

void initColor(colorType color[]) {
    for(int i = 'A'; i < maxVert; i++) {
        color[i] = white;
    }
}

void createQ(Qtype *&Qhead, Qtype *&Qtail) {
    Qhead = new Qtype;
    Qtail = new Qtype;
    Qhead -> wt = -1;
    Qtail -> wt = 1000;
    Qhead -> link = Qtail;
    Qtail -> link = NULL;
}

bool emptyQ(Qtype *Qhead, Qtype *Qtail) {
    return (Qhead -> link == Qtail);
}

void deQ(Qtype *Qhead, Qtype *Qtail, char &v1, char &v2, int &wt) {
    Qtype *c;
    c = Qhead -> link;
    Qhead -> link = c -> link;

    v1 = c -> v1;
    v2 = c -> v2;
    wt = c -> wt;

    delete c;
}

void enQ(Qtype *Qhead, Qtype *Qtail, char v1, char v2, int wt) {
    Qtype *knew, *prior, *next;

    knew = new Qtype;
    knew -> v1 = v1;
    knew -> v2 = v2;
    knew -> wt = wt;

    prior = Qhead;
    next = Qhead -> link;
    while(next != Qtail && knew -> wt >= next -> wt) {
        prior = next;
        next = next -> link;
    }
    prior -> link = knew;
    knew -> link = next;
}

void createGraph(int adj[][maxVert]) {
    init2(adj);
    ifstream inf("input.txt");
    char v1 = ' ', v2 = ' ';
    int wt = 0;

    while(!inf.eof()) {
        inf >> v1 >> v2 >> wt;
        adj[v1][v2] = wt;
        adj[v2][v1] = wt;
    }
}

void printGraph(ofstream &ofs, int adj[][maxVert]) {

    ofs << setw(45) << "Two Dimensional Adjacency Matrix" << endl;
    ofs << '\t' << ' ';
    for(int i = 0; i < 50; i++) ofs << '_';
    ofs << endl;

    ofs << setw(5) << "_";
    for(int j = 'A'; j <= 'M'; j++) {
        ofs << setw(4) << (char)j;
    }

    ofs << endl;

    for(int i = 'A'; i <= maxVert; i++) {
        ofs << setw(5) << (char)i;
        for(int j = 'A'; j <= 'M'; j++)
            ofs << setw(4) << adj[i][j];
        ofs << endl;
    }
}


void mst(Qtype *Qhead, Qtype *Qtail, int adj[][maxVert], colorType color[], edgeType ans[], char start) {
    int count = 'A';
    char v1, v2;
    int wt;

    enQ(Qhead, Qtail, start, 'x', 0);
    color[start] = grey;

    while(!emptyQ(Qhead, Qtail)) {
        deQ(Qhead, Qtail, v1, v2, wt);
        if(color[v1] != black) {
            if(wt != 0 || v1 == start) {
                ans[count].v1 = v1;
                ans[count].v2 = v2;
                ans[count].wt = wt;
                count++;
            }
            for(char u = 'A'; u <= 'M'; u++) {
                if(adj[v1][u] != 0 && color[u] != black) {
                    enQ(Qhead, Qtail, u, v1, adj[v1][u]);
                    color[u] = grey;
                }
            }
        }
        color[v1] = black;
    }
} 

void printmst(ofstream &ofs, edgeType ans[]) {
    int totWt = 0;
    ofs << endl << endl << endl;

    ofs << setw(4) << "MST" << endl;
    ofs << "_____" << endl;
    for(char i = 'A'; i <= 'M'; i++) {
        ofs << ans[i].v1 << ' ';
        ofs << ans[i].v2 << ' ';
        ofs << ans[i].wt << endl;
        totWt += ans[i].wt;
    }

    ofs << endl << "Total weight: " << totWt;
}

int main() {
    ofstream ofs("output.txt");
    int adj[maxVert][maxVert];
    edgeType ans[maxVert - 'A'];
    Qtype *Qhead, *Qtail;
    colorType color[maxVert];

    init1(ans);
    initColor(color);
    
    createGraph(adj);
    printGraph(ofs, adj);

    createQ(Qhead, Qtail);
    mst(Qhead, Qtail, adj, color, ans, 'A');
    printmst(ofs, ans);

    return 0;
}