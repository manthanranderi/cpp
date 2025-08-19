#include<iostream>
#include<string.h>
using namespace std;

class BankAccount{
    private:
        int accountNumber;
        char holderName[100];

    protected:
        double balance;

    public:
        void deposit()
        {
            double deposit;

            cout << "Enter Deposit Value: ";
            cin >> deposit;
            balance += deposit;

            cout << deposit << " Deposited" << endl;
        }

        void withdraw()
        {
            double withdraw;

            cout << "Enter WithDraw Value: ";
            cin >> withdraw;
            
            if (withdraw > balance)
            {
                cout << "Insuficient Balance" << endl;
            }
            else
            {
                balance -= withdraw;
                cout << withdraw << " Withdrawed" << endl;
            }
        }
        
        void getBalance()
        {
            cout << "Your Current Balance is: " << balance << endl;
        }

        void getAccountInfo()
        {
            cout << "Account Number: ";
            cin >> accountNumber;

            cout << "Holder Name: ";
            cin >> holderName;

            cout << "Initial Balance: ";
            cin >> balance;
        }

        void accountInfo()
        {
            cout << "Account Number: " << accountNumber
                 << "\nHolder Name: " << holderName
                 << "\nTotal Balance: " << balance << endl;
        }
};

class SavingsAccounts : public BankAccount{
    protected: 
        double interestValue;

    public: 
        void interest()
        {
            double rate;

            cout << "Enter Interest Rate: ";
            cin >> rate;

            int time = 1;

            interestValue = balance * (rate / 100) * time;
            cout << "Interest for 1 year is: " << interestValue << endl;
        }
};

class ChekingAccount : public BankAccount {
    private: 
        double limit;

    public:
        void checkOverdraft() {
            cout << "Enter Limit of OverDraft: ";
            cin >> limit;
        }

        void withdraw()
        {
            double withdraw, grandTotal;

            cout << "Enter WithDraw Value: ";
            cin >> withdraw;
            
            grandTotal = balance + limit;
            if (withdraw > grandTotal)
            {
                cout << "Insuficient Balance" << endl;
            }
            else
            {
                balance -= withdraw;
                cout << withdraw << " Withdrawed" << endl;
            }
        }
};

class FixedDeposit : public BankAccount{
    private: 
        double rate, interest;
        int term;

    public: 
        void calculateInterest()
        {
            cout << "Enter Annual Interest Rate: ";
            cin >> rate;

            cout << "Enter Terms in Month: ";
            cin >> term;

            interest = (balance * rate * term) / 1200;
            cout << "Interest for " << term << " Month: " << interest << endl;
        }
};

int main()
{
    int choice, choice2 = 0;

    cout << "Please Select the Account Type: \n";
    cout << "1. Savings \n2. Checkings\n3. Fixed Deposits" << endl;
    cout << "Please Enter the Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        SavingsAccounts abc;
        abc.getAccountInfo();

        while (choice2 != 6)
        {
            cout << "\nMenu: \n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Info\n5. Calculate Interest\n6. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                abc.deposit();
                break;
            case 2:
                abc.withdraw();
                break;
            case 3:
                abc.getBalance();
                break;
            case 4:
                abc.accountInfo();
                break;
            case 5:
                abc.interest();
                break;
            case 6:
                cout << "Exited ..." << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        ChekingAccount checkObj;
        checkObj.getAccountInfo();
        checkObj.checkOverdraft(); 

        while (choice2 != 6)
        {
            cout << "\nMenu: \n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Info\n5. Set Overdraft Limit\n6. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                checkObj.deposit();
                break;
            case 2:
                checkObj.withdraw();
                break;
            case 3:
                checkObj.getBalance();
                break;
            case 4:
                checkObj.accountInfo();
                break;
            case 5:
                checkObj.checkOverdraft();
                break;
            case 6:
                cout << "Exited ..." << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
        }
    }
    else if (choice == 3)
    {
        FixedDeposit obj;
        while (choice2 != 6)
        {
            cout << "\nMenu: \n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Info\n5. Set Overdraft Limit\n6. Exit\n";
            cout << "Enter Choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                obj.deposit();
                break;
            case 2:
                obj.withdraw();
                break;
            case 3:
                obj.getBalance();
                break;
            case 4:
                obj.accountInfo();
                break;
            case 5:
                obj.calculateInterest();
                break;
            case 6:
                cout << "Exited ..." << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }
        }
    }

}