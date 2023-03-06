/******************************************************************************/
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program assignment03pe04: Passing a Two-Dimensional Array                  */
/*                                                                            */
/* Approximate completion time: 15 minutes                                    */
/******************************************************************************/

/*
   This program calculates the sum of user-input integers in a 
   3x4 array. 
*/

#include <iostream>
#include <array>

using namespace std;

const int ARRAY_NUM = 3;
const int SIZE = 4;

int sum(int arr[][SIZE], int array_num, int size);

int main()
{
    int arr[ARRAY_NUM][SIZE];

    // Nested for loops to populate array with user input 
    for (int i = 0; i < ARRAY_NUM; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Enter a number to be stored ";
            cout << "in array[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
            cout << endl;
        }
    }

    cout << "The sum is: " << sum(arr, ARRAY_NUM, SIZE) << endl;

    return 0;

}

/******************************************************************************/
/* Function: sum                                                              */
/*                                                                            */
/* Description: Calculates the sum of integers in a 3x4 array                 */
/*                                                                            */
/* Data in: a 2-D array, along with dimensions of array                       */
/*                                                                            */
/* Data out: sum (total of values in 2-D array)                               */
/******************************************************************************/
int sum(int arr[][SIZE], int array_num, int size)
{
    // Initialize sum to 0
    int sum = 0;

    // Nested for loop to increase sum by appropriate amount 
    for (int i = 0; i < ARRAY_NUM; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += arr[i][j];
        }
    }

    return sum;

}