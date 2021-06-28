#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    ifstream ifs(argv[1], ios::binary);
    if(!ifs) {
        cerr << "Destination error" << endl;
    }

    ofstream ofs(argv[2], ios::binary);
    if(!ofs) {
        cerr << "Destination error" << endl;
    }

    const int BUFFSIZE = 4096;
    char ch[BUFFSIZE];
    while(true) {
        ifs.read(ch, BUFFSIZE); // should be reading from a socket instead
        cout << ch;
        //here is UDP/TCP
        ofs.write(ch,ifs.gcount()); //replace with UDP packet send
        if (ifs.gcount() != BUFFSIZE) break;
    }
    ifs.close();
    ofs.close();


    return 0;
}