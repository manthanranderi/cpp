
#include<iostream>
using namespace std;

int main()
{
    int i, j, row, col;

    cout<<"Please Enter the Row Size: ";
    cin>>row;

    if (row <= 0)
    {
        cout<<"Row Size Must be Greater than 0";
    }
    else
    {
        cout<<"Please Enter the Col Size: ";
        cin>>col;

        if (col <= 0)
        {
            cout<<"Col Size must be Greater than 0";
        }
        else
        {
            int array[row][col];
        
            cout<<"\nPlease Enter the Elements in 2d Array: \n";
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    cout<<"Array["<<i<<"]["<<j<<"]: ";
                    cin>>array[i][j];
                }
            }
        
            int max = array[0][0];
        
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    if (array[i][j] > max)
                    {
                        max = array[i][j];
                    }
                }
            }
            cout<<"\nLargest Element in 2D Array is: "<<max;
        }
    }
}
