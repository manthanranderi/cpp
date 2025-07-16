#include <iostream>
using namespace std;

int main()
{
    int rows = 5;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        for (int l = 1; l <= 2 * (rows - i); l++)
        {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
