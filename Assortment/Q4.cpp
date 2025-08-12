
#include<iostream>
using namespace std;

int main()
{
    int col, row, i, j, sum=0, sum2=0;

    cout<<"Enter Row Size: ";
    cin>>row;

    if (row <= 0)
    {
        cout<<"Row size must be Greater than 0";
    }
    else
    {
        cout<<"Enter Col Size: ";
        cin>>col;

        if (col <= 0)
        {
            cout<<"Col size must be Greater than 0";
        }
        else{

            int array[row][col], row_no, col_no;

            cout<<"\nPlease Enter the Elements: \n";
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    cout<<"Array["<<i<<"]["<<j<<"]: ";
                    cin>>array[i][j];
                }
            }

            cout<<"\nPlease Enter Row No. to Sum: ";
            cin>>row_no;

            cout<<"Please Enter Col No. to Sum: ";
            cin>>col_no;

            cout<<"\nRow Elements: \n";
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    if (i == row_no)
                    {
                        cout<<array[i][j]<<"  ";
                        sum+= array[i][j];
                    }
                }
            }

            cout<<"\nCol Elements: \n";
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    if (j == col_no)
                    {
                        cout<<array[i][j]<<"  ";
                        sum2+= array[i][j];
                    }
                }
            }

            cout<<"\nSum of Row Element: "<<sum<<"\n";
            cout<<"Sum of Col Element: "<<sum2<<"\n";
        }
    }
}