// This program reads in from the keyboard a record of financial information
// consisting of a person's name, income, rent, food costs, utilities and
// miscellaneous expenses. It then determines the net money
// (income minus all expenses)and places that information in a record
// which is then written to an output file.

// Bisshoy Anwar 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

const int NAMESIZE = 15;
const int MAX_PEOPLE = 50;


// declare a structure to hold name and financial information 
struct budget	
{
	char name[NAMESIZE + 1];
	float income;		// person's monthly income 
	float rent;			// person's monthly rent
	float food;			// person's monthly food bill 
	float utilities;	// person's monthly utility bill 
	float miscell;		// person's other bills
	float net;			// person's net money after bills are paid
};

typedef budget record[MAX_PEOPLE]; 

int main()
{
    char choice;

	fstream indata;
	ofstream outdata;	// output file of
						// student. 

	indata.open("income.dat", ios::out | ios::binary);	// open file as binary
														// output.

	outdata.open("student.out");	// output file that we
									// will write student
									// information to. 

	outdata << left << fixed << setprecision(2);	// left indicates left
													// justified for fields 
    
	record person;	// defines person to be a record

    cout << "Enter the following information" << endl;

    cout << "Person's name: ";
    cin.getline(person[0].name, NAMESIZE);

    cout << "Income: ";
    cin >> person[0].income;

    cout << "Rent: ";
    cin >> person[0].rent;

    cout << "Food: ";
    cin >> person[0].food;

    cout << "Utilities: ";
    cin >> person[0].utilities;

    cout << "Misc: ";
    cin >> person[0].miscell;


    person[0].net = person[0].income - (person[0].rent 
                             + person[0].food + person[0].utilities 
                             + person[0].miscell);

    cout << "Enter a Y if you would like to input more data" << endl;
    cin >> choice;

    int people_index = 1;

    while (toupper(choice) == 'Y')
    {
        cout << "Enter the following information" << endl;

        cout << "Person's name: ";
        cin.ignore();

        cin.getline(person[people_index].name, NAMESIZE);

        cout << "Income: ";
        cin >> person[people_index].income;

        cout << "Rent: ";
        cin >> person[people_index].rent;

        cout << "Food: ";
        cin >> person[people_index].food;

        cout << "Utilities: ";
        cin >> person[people_index].utilities;

        cout << "Misc: ";
        cin >> person[people_index].miscell;


        person[people_index].net = person[people_index].income - (person[people_index].rent 
                                 + person[people_index].food + person[people_index].utilities 
                                 + person[people_index].miscell);

        people_index++;

        cout << "Enter a Y if you would like to input more data" << endl;
        cin >> choice;

    } 


    indata.write(reinterpret_cast<char *>(person), sizeof(person));
	indata.close();

    indata.open("income.dat");
    indata.write(reinterpret_cast<char *>(person), sizeof(person));


	// write information to output file
	outdata << left << setw(20) << "Name" 
            << setw(10) << "Income" 
            << setw(10) << "Rent"
		    << setw(10) << "Food" 
            << setw(15) << "Utilities" 
            << setw(15) << "Miscellaneous" 
            << setw(10) << "Net Money" << endl << endl;

    for (int i = 0; i < people_index; i++) {
        outdata << left << setw(20) << person[i].name 
                << setw(10) << person[i].income 
                << setw(10) << person[i].rent
		        << setw(10) << person[i].food 
                << setw(15) << person[i].utilities 
                << setw(15) << person[i].miscell 
                << setw(10) << person[i].net << endl;
    }

    indata.close();
    outdata.close();

	return 0;

}

