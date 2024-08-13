#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string name, int accNo, string accType, double bal) {
        customerName = name;
        accountNumber = accNo;
        accountType = accType;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Updated balance: " << balance << endl;
    }

    void displayBalance() {
        cout << "Current balance: " << balance << endl;
    }

    virtual void withdraw(double amount) = 0; // Pure virtual function for withdrawal
};

class Curr_acct : public Account {
private:
    double minBalance;
    double serviceCharge;

public:
    void setDetails(double minBal, double charge) {
        minBalance = minBal;
        serviceCharge = charge;
    }

    void withdraw(double amount) override {
        if (balance - amount < minBalance) {
            cout << "Minimum balance requirement not met. A service charge of " << serviceCharge << " will be imposed.\n";
            balance -= serviceCharge;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Updated balance: " << balance << endl;
        }
    }

    void checkMinimumBalance() {
        if (balance < minBalance) {
            cout << "Minimum balance not maintained. Imposing service charge of " << serviceCharge << ".\n";
            balance -= serviceCharge;
        }
        displayBalance();
    }
};

class Sav_acct : public Account {
private:
    double interestRate;

public:
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void computeAndDepositInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added. Updated balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance.\n";
        }
    }
};

int main() {
    // Current Account Example
    Curr_acct currentAcc;
    currentAcc.initialize("John Doe", 12345, "Current", 5000);
    currentAcc.setDetails(2000, 100);
    currentAcc.deposit(1000);
    currentAcc.withdraw(3000);
    currentAcc.checkMinimumBalance();

    cout << endl;

    // Savings Account Example
    Sav_acct savingsAcc;
    savingsAcc.initialize("Jane Doe", 54321, "Savings", 10000);
    savingsAcc.setInterestRate(5); // 5% interest rate
    savingsAcc.computeAndDepositInterest();
    savingsAcc.withdraw(2000);
    savingsAcc.displayBalance();

    return 0;
}