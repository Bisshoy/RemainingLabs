/******************************************************************************/
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program assignment03pe02: Call by Reference                                */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

/*
   This program swaps the values of two variables by reference. 
*/

#include <iostream> 

using namespace std; 

void swap(int&, int&); 

int main() 
{
	int x, y; 

	cout << "Please enter the first value, x: ";
	cin >> x;
	cout << endl;

	cout << "Please enter the second value, y: ";
	cin >> y;
	cout << endl;

	// Call swap function 
	swap(x, y); 

    cout << "After the swap, x is equal to " << x;
    cout << " and y is equal to " << y << endl;
	
	return 0;

}

/******************************************************************************/
/* Function: swap                                                             */
/*                                                                            */
/* Description: Swaps two variables' value via reference                      */
/*                                                                            */
/* Data in: References to two integers in main function                       */
/*                                                                            */
/* Data out: Void                                                             */
/******************************************************************************/
void swap(int& a, int& b)
{
	// Pretty self-explanatory 
	int temp = a; 
	a = b;
	b = temp;
	
}