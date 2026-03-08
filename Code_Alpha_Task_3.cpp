#include <iostream>
#include <string>
using namespace std;
class Transaction{
public:
    int id;
    string type;
    double amount;
    void display(){
        cout << "Transaction ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Amount: " << amount << endl;
    }
};
class Customer{
public:
    int customerID;
    string name,phone;
    void createCustomer(){
        cout << "Enter Customer ID: " << endl;
        cin >> customerID;
        cout << "Enter Name: " << endl;
        cin >> name;
        cout << "Enter Phone: " << endl;
        cin >> phone;
    }
    void displaycustomer(){
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};
class Account
{
public:
    double accountNumber;
    double balance;

    Transaction transactions[100];
    int transactionCount = 0;

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        balance = 0;
    }

    void deposit()
    {
        double amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        transactions[transactionCount].id = transactionCount + 1;
        transactions[transactionCount].type = "Deposit";
        transactions[transactionCount].amount = amount;

        transactionCount++;

        cout << "Deposit Successful\n";
    }

    void withdraw()
    {
        double amount;

        cout << "Enter Withdraw Amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance\n";
            return;
        }

        balance -= amount;

        transactions[transactionCount].id = transactionCount + 1;
        transactions[transactionCount].type = "Withdraw";
        transactions[transactionCount].amount = amount;

        transactionCount++;

        cout << "Withdraw Successful\n";
    }

    void showBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }

    void showTransactions()
    {
        cout << "\nTransaction History\n" << endl;

        for (int i = 0; i < transactionCount; i++)
        {
            transactions[i].display();
        }
    }
};
int main(){
    Customer c1;
    Account a1;
    int choice;
    do
    {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Show Balance\n";
        cout << "6. Show Transactions\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c1.createCustomer();
            break;

        case 2:
            a1.createAccount();
            break;

        case 3:
            a1.deposit();
            break;

        case 4:
            a1.withdraw();
            break;

        case 5:
            a1.showBalance();
            break;

        case 6:
            a1.showTransactions();
            break;

        case 0:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 0);
    
}