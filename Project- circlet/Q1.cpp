#include <iostream>
using namespace std;
main()
{

    for (int i = 1; i <= 5; i++)
    {
        int num = 41;

        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}