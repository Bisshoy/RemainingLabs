/******************************************************************************/
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program assignment03pe05: Inner Product of Two Arrays                      */
/*                                                                            */
/* Approximate completion time: 10 minutes                                    */
/******************************************************************************/

/*
   This program calculates the inner product of two arrays. (The inner
   product is the sum of the products of array elements of corresponding
   indices.)
*/

#include <iostream>
#include <array>

using namespace std;

const int SIZE = 4;

float inner(float u[], float v[], int size);

int main()
{
    float arr1[SIZE]; 
    float arr2[SIZE]; 
    float arr1_userNum;
    float arr2_userNum;
    int arr1_index = 1;
    int arr2_index = 1;

    // Populate first array 
    for (auto& x : arr1) {
        cout << "Enter in number " << arr1_index << " (u array): ";
        cin >> arr1_userNum;
        x = arr1_userNum;
        arr1_index++;
        cout << endl;
    }

    // Populate second array 
    for (auto& x : arr2) {
        cout << "Enter in number " << arr2_index << " (v array): ";
        cin >> arr2_userNum;
        x = arr2_userNum;
        arr2_index++;
        cout << endl;
    }

    // Call inner function 
    cout << "The inner product of arrays u and v is ";
    cout << inner(arr1, arr2, SIZE) << endl;

    return 0;

}

/******************************************************************************/
/* Function: inner                                                            */
/*                                                                            */
/* Description: Finds inner product of two arrays (sum of products of arrays' */
/*              corresponing elements)                                        */
/*                                                                            */
/* Data in: Two arrays of equal size, as well as the size of the arrays       */
/*                                                                            */
/* Data out: float (inner product of the arrays)                              */
/******************************************************************************/
float inner(float u[], float v[], int size)
{
    // Initalize total to 0 
    float innerProduct = 0;

    // Increase innerProduct by appropriate amount 
    for (int i = 0; i < size; i++) {
        innerProduct += (u[i] * v[i]);
    }

    return innerProduct;

}
