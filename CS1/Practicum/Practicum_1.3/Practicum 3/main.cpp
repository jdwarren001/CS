/*******************************************************************************
 * Consider the following C++ program in which the statements are in the
 * incorrect order. Rearrange the statements so that it prompts the user to input
 * the length and width of a rectangle and output the area and perimeter of the
 * rectangle.
 ********************************************************************************/
/* #include <iostream>
{
    int main (int argc, char* argv[])
    cout << "Enter the length: ";
    cin >> length;
    cout << endl;
    int length;
    area = length * width;
    return 0;
    int width;
    cin>> width;
    cout << "Enter the width: "
    cout << endl;
    cout << "Area = " << area << endl;
    cout << "Perimeter = " << perimeter << endl;
    int area;
    using namespace std;
    int perimeter;
    }
*/
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int length, width, perimeter, area;

    cout << "Enter the length: ";
    cin >> length;
    cout << endl;
    
    cout << "Enter the width: ";
    cin >> width;
    cout << endl;
    
    perimeter = length * 2 + width * 2;
    cout << "Perimeter = " << perimeter << endl;
    
    area = length* width;
    cout << "Area = " << area << endl;
    
    
    
    
    
    
    
    
    
    return 0;
}
