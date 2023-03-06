// Bisshoy Anwar 

#include <iostream>
#include <cctype>

using namespace std;

class SavingsAccount
{
    private:
        int dollars;
        int cents;
        void normalizeCents();

    public:
        SavingsAccount(int d = 0, int c = 0) {
            dollars = d;
            cents = c;
            normalizeCents();
        }

        void makeDeposit(int d, int c);
        void makeWithdrawal(int d, int c);
        void showBalance() const;
};

int main()
{
    int dollars;
    int cents;

    cout << "Please input the inital dollars" << endl;
    cin >> dollars;
    cout << "Please output the initial cents" << endl;
    cin >> cents;

    SavingsAccount bank1 = SavingsAccount(dollars, cents);
    SavingsAccount bank2 = SavingsAccount();

    const int d = 77;
    const int c = 77;

    cout << "\nBank 1 before transaction: ";
    bank1.showBalance();
    cout << "Bank 2 before transaction: ";
    bank2.showBalance();

    bank1.makeWithdrawal(d, c);
    bank2.makeDeposit(d, c);
    cout << endl;

    cout << "Bank 1 Balance: ";
    bank1.showBalance();
    cout << "Bank 2 Balance: ";
    bank2.showBalance();

    return 0;

}
       
void SavingsAccount::makeDeposit(int d, int c)
{
    dollars += d;
    cents += c;
    normalizeCents();

}

void SavingsAccount::makeWithdrawal(int d, int c)
{
    dollars -= d;
    cents -= c;
    normalizeCents();

}

void SavingsAccount::showBalance() const
{
    cout << "Dollars = " << dollars << "    Cents = " << cents << endl;

}

void SavingsAccount::normalizeCents()
{
    while (cents >= 100) {
        dollars++;
        cents = cents - 100;
    }

    while (cents < 0) {
        dollars--;
        cents = cents + 100;
    }
}