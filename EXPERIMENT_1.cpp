/**Create a class BankAccount with private member variables
accountNumber, balance, and ownerName. Provide public methods to
deposit, withdraw, and display the balance.*/

#include <iostream>
                   
using namespace std;

class BankAccount
{
    int accountnumber;
    double balance,d,w;
    string ownerName;

    public:
    void getData();
    void deposit();
    void withdraw();
    void display();
};

    void BankAccount::getData()
    {
        cout<<"Enter the account number:"<<endl;
        cin>>accountnumber;
        cout<<"Enter the balance in bank account:"<<endl;
        cin>>balance;
        cout<<"Enter the account holder name:"<<endl;
        cin>>ownerName;
    }
    

    void BankAccount::deposit()
    {
        cout<<"Enter the amount to be deposited:"<<endl;
        cin>>d;
    }

    

    void BankAccount::withdraw()
    {
        cout<<"Enter the amount to be withdrawn:"<<endl;
        cin>>w;
    if (balance<w)
    {
        cout<<"Sufficient amount not available"<<endl;
    }
    else
    {
        cout<<"Amount withdrawn"<<endl;
    }

    }
    

    void BankAccount::display()
    {
        cout<<"Display the current bank balance:"<<balance+d-w<< "Rupees"<<endl;
    }
int main(){
    BankAccount shikhar;
    shikhar.getData();
    shikhar.display();
    shikhar.withdraw();
    shikhar.deposit();
    shikhar.display();
    return 0;
}