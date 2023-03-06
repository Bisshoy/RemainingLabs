/******************************************************************************/
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program assignment03pe01: Iterative Fibonacci                              */
/*                                                                            */
/* Approximate completion time: 20 minutes                                    */
/******************************************************************************/

/*
   This program prints out the nth term of the fibonacci sequence, and
   allows the user to keep doing that until they choose to exit
   the program.
*/

#include <iostream>
#include <array>

using namespace std;

void printMenu();
void fibonacci(int);

int main()
{
    int choice; 
    int n;

    cout << "Welcome to Fibonacci ";
    cout << "Computation Program" << endl << endl;

    printMenu();
    cin >> choice; 

    // Input validation for menu choice 
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Retry" << endl << endl;
        printMenu();
        cin >> choice; 
    }

    // Do-while loop for fibonacci call
    while (choice != 2) {
        switch (choice) {
            case 1: 
                cout << "Enter n: ";
                cin >> n;

                while (!(n >= 1)) {
                    cout << "n should be a positive ";
                    cout << "integer (n >= 1). Retry." << endl;
                    cout << "Enter n: ";
                    cin >> n;
                }

                fibonacci(n);

                cout << endl;

                // Loop back 
                printMenu();
                cin >> choice; 

                // Input validation for menu (again)
                while (choice != 1 && choice != 2) {
                    cout << "Invalid choice. Retry" << endl << endl;
                    printMenu();
                    cin >> choice; 
                }

                break;

            // Exit for Choice 2
            case 2:
                break;
        }
    } 

    cout << "Thank you!" << endl;

    return 0;

}

/******************************************************************************/
/* Function: printMenu                                                        */
/*                                                                            */
/* Description: Prints the menu for the program                               */
/*                                                                            */
/* Data in: None                                                              */
/*                                                                            */
/* Data out: Void                                                             */
/******************************************************************************/
void printMenu()
{
    cout << " 1- Calculate Fibonacci" << endl;
    cout << " 2- Exit" << endl;
    cout << "(Enter 1 or 2)" << endl << endl;

}

/******************************************************************************/
/* Function: fibonacci                                                        */
/*                                                                            */
/* Description: Prints the nth term in fibonacci sequence                     */
/*                                                                            */
/* Data in: integer n (for that nth term of sequence)                         */
/*                                                                            */
/* Data out: Void                                                             */
/******************************************************************************/
void fibonacci(int n)
{
    long long arr[n];

    // Set two initial values so we can add
    arr[0] = 1; 
    arr[1] = 1;

    // Populate further values based on n
    for (int i = 2; i < n; i++) {

        arr[i] = arr[i-2] + arr[i-1];
    }

    // Print out statement 
    cout << "fibonacci(" << n << ") = " << arr[n-1] << endl;

}