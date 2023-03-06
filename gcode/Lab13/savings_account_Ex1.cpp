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
        void openAccount(int d, int c);
        void makeDeposit(int d, int c);
        void makeWithdrawal(int d, int c);
        void showBalance() const;
};

int main()
{
    SavingsAccount account1;
    int dollars;
    int cents;
    char choice; 

    cout << "Please input the inital dollars" << endl;
    cin >> dollars;
    cout << "Please output the initial cents" << endl;
    cin >> cents;
    cout << endl;

    // Open account 
    account1.openAccount(dollars, cents);

    cout << "Would you like to make a deposit? Y or y for yes" << endl;
    cin >> choice;

    while (toupper(choice) == 'Y') {
        cout << "Please input the dollars to be deposited" << endl;
        cin >> dollars;
        cout << "Please input the cents to be deposited" << endl;
        cin >> cents;
        account1.makeDeposit(dollars, cents);

        cout << "\nWould you like to make a deposit? Y or y for yes" << endl;
        cin >> choice;
    }

    cout << endl << endl;

    cout << "Would you like to make a withdrawal? Y or y for yes" << endl;
    cin >> choice;

    while (toupper(choice) == 'Y') {
        cout << "Please input the dollars to be withdrawn" << endl;
        cin >> dollars;
        cout << "Please input the cents to be withdrawn" << endl;
        cin >> cents;
        account1.makeWithdrawal(dollars, cents);

        cout << "\nWould you like to make a withdrawal? Y or y for yes" << endl;
        cin >> choice;
    }

    cout << endl;
    account1.showBalance();

    return 0;

}

void SavingsAccount::openAccount(int d, int c)
{
    dollars = d;
    cents = c;
    normalizeCents();

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
    cout << "Dollars = " << dollars << "\tCents = " << cents << endl;

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

