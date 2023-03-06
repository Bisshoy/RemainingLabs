#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_SIZE = 50;

bool isPalindrome(char[]);

int main()
{
    char arr[MAX_SIZE + 1];

    cout << "Please enter string" << endl;
    cin.getline(arr, MAX_SIZE + 1);
    

    if (isPalindrome(arr)) {
        cout << "Your string is a palindrome!" << endl;
    }

    else {
        cout << "Your string is not a palindrome" << endl;
    }

    return 0;

}

bool isPalindrome(char array[]) 
{
    bool isPal = true;
    int size = strlen(array);

    for (int i = 0, j = size - 1; i < size && j > 0; i++, j--) {
        if (array[i] != array[j]) {
            isPal = false;
        }
    }

    return isPal;

}

