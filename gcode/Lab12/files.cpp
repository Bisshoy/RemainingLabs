// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

// Bisshoy Anwar 

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Fill in the code to define payfile as an input file
	ifstream payfile;
	ofstream outfile;
	float gross;
	float net;
	float hours;
	float payRate;
	float stateTax;
	float fedTax;

	payfile.open("payroll.dat");
	outfile.open("output.dat");

	if (!payfile)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		exit(1);
	}

	outfile << fixed << setprecision(2) << showpoint; 
	outfile << "PayRate	       Hours	Gross Pay	Net Pay" << endl << endl;

	// Fill in code to prime the read for the payfile file.
	payfile >> hours;

	// Fill in code to write a loop condition to run while payfile has more
	// data to process.
	while (payfile)
	{
		payfile >> payRate >> stateTax >> fedTax;

		gross = payRate * hours;
		net = gross - (gross * stateTax) - (gross * fedTax);

		outfile << payRate << setw(15) << hours << setw(12) << gross << setw(12) << net << endl;

				   // Fill in the code to finish this with the appropriate
			       // variable to be input
		payfile >> hours;

	}

	payfile.close();
	outfile.close();

	return 0;

}

