#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {

    ifstream source("test_image.jpg", ios::binary);
    ofstream dest("image_test_copy.jpg", ios::binary);

    istreambuf_iterator<char> begin_source(source);
    istreambuf_iterator<char> end_source;
    ostreambuf_iterator<char> begin_dest(dest); 
    copy(begin_source, end_source, begin_dest);

    source.close();
    dest.close();

    return 0;
}