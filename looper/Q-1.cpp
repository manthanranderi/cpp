#include <iostream>
using namespace std;

int main() {
    char letter = 'A';

    do {
        cout << letter << " ";
        letter += 4; 
    } while (letter <= 'Z');

    cout << endl;
    return 0;
}