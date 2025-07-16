#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        if (i == 1 || i == 3)
        {
            for (int j = 1; j <= 6; j++)
            {
                cout << "* ";
            }
        }
        else if (i == 2)
        {
            cout << "*         *";
        }
        else
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
