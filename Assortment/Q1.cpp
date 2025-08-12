// wap to print nagative numbers

#include<iostream>
using namespace std;

int main()
{

    
    int size, i;

    cout<<"Array Size: ";
    cin>>size;

    if (size <=0 )
    {
        cout<<"Array size is must be Greater than 0";
    }
    else{
        int array[size];
    
        cout<<"\nPlease Enter the Array Elements: \n";
        for(i=0; i<size; i++)
        {
            cout<<"Array["<<i<<"]: ";
            cin>>array[i];
        }
    
        cout<<"\nNegative Elements: \n";
        for(i=0; i<size; i++)
        {
            if (array[i] < 0)
            {
                cout<<"Array["<<i<<"]: "<<array[i]<<endl;
            }
        }
    }

}