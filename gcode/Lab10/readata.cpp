#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    char last[SIZE];

    cout << "Enter your last name using no more than 9 characters." << endl;
    cin.getline(last, 10);

    cout << last << endl;

    return 0;

}