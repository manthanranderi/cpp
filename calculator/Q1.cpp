#include <iostream>
using namespace std;
int addition(int a, int b)
{
    return a + b;
}
int substraction(int a, int b)
{
    return a - b;
}
int Multiplication(int a, int b)
{
    return a * b;
}
int dividation(int a, int b)
{
    return (b != 0) ? a / b : 0;
}
int modulos(int a, int b)
{
    return (b != 0) ? a % b : 0;
}
int main()
{
    int choice, a, b;

    do
    {
        cout << "Enter 1 for addition(+) : " << endl;
        cout << "Enter 2 for substraction(-) : " << endl;
        cout << "Enter 3 for multiplication(*) : " << endl;
        cout << "Enter 4 for dividation(/) : " << endl;
        cout << "Enter 5 for modulos(%) : " << endl;
        cout << "Enter 0 for exit : " << endl
             << endl;
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting the calculator.\n";
            break;
        }

        cout << "Enter The First Number : ";
        cin >> a;

        cout << "Enter The Second Number : ";
        cin >> b;

        switch (choice)
        {
        case 1:
            cout << "Result: " << addition(a, b) << endl;
            break;

        case 2:
            cout << "Result: " << substraction(a, b) << endl;
            break;
        case 3:
            cout << "Result: " << Multiplication(a, b) << endl;
            break;
        case 4:
            cout << "Result: " << dividation(a, b) << endl;
            break;
        case 5:
            cout << "Result: " << modulos(a, b) << endl;
            break;

        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (true);

    return 0;
}