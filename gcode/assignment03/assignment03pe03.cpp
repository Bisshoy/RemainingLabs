/******************************************************************************/
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program assignment03pe03: Reverse                                          */
/*                                                                            */
/* Approximate completion time: 10 minutes                                    */
/******************************************************************************/

/*
   This program prints out the contents of a user-filled array 
   in reverse. 
*/

#include <iostream>
#include <array>

using namespace std;

const int SIZE = 10;

int main()
{
    int arr[SIZE];
    int num = 1;
    int userNum;

    // Iterates through to populate array with user input
    for (auto& x : arr) {
        cout << "Enter number " << num++ << ": ";
        cin >> userNum;
        x = userNum;
    }
    
    cout << "\nIn reverse order, the numbers you entered are: ";

    // Starts from end, prints through first element 
    for (int i = (SIZE - 1); i >= 0; i--) {
        cout << arr[i] << " "; 
    }

    cout << endl;

    return 0;

}

