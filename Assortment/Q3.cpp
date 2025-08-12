#include <iostream>
using namespace std;
int main()
{
    int r, c;

    cout << "Enter the arrays row size : ";
    cin >> r;
    cout << "Enter the arrays column size : ";
    cin >> c;

    int array[r][c];
    cout << "Enter arrays element : " << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "array[" << i << "][" << j << "] : ";
            cin >> array[i][j];
        }
    }

    cout << "The transpose matrix of an array :\n";

    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}