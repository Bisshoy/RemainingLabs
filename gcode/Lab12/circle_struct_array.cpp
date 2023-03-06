// Bisshoy Anwar 

#include <iostream>
#include <fstream> 
#include <iomanip>
#include <cmath> 
#include <cctype>

using namespace std;

const int MAX_RECORDS = 20;
const float PI = 3.14159;

struct dimensions
{
    float radius;
    float diameter;
    float area;
    float circumference;
};

typedef dimensions circle[MAX_RECORDS];


int main()
{
    char choice;

    fstream indata;
    ofstream outdata;

    indata.open("circledata.dat", ios::out | ios::binary);
    outdata.open("circles.out");

    outdata << left << fixed << setprecision(2);

    circle O;

    cout << "Enter the following information" << endl;

    cout << "Radius of circle: ";
    cin >> O[0].radius;

    O[0].diameter = 2 * O[0].radius;
    O[0].area = PI * O[0].radius * O[0].radius;
    O[0].circumference = PI * O[0].diameter;

    cout << "Enter a Y if you would like to input more data" << endl;
    cin >> choice;
    cout << endl;

    int circle_index = 1;

    while (toupper(choice) == 'Y')
    {
        cout << "Enter the following information" << endl;

        cout << "Radius of circle: ";
        cin >> O[circle_index].radius;

        O[circle_index].diameter = 2 * O[circle_index].radius;
        O[circle_index].area = PI * O[circle_index].radius * O[circle_index].radius;
        O[circle_index].circumference = PI * O[circle_index].diameter;

        circle_index++;

        cout << "Enter a Y if you would like to input more data" << endl;
        cin >> choice;
        cout << endl;
        cin.ignore();

    }

    indata.write(reinterpret_cast<char *>(O), sizeof(O));

    indata.close();

    indata.open("circledata.dat", ios::in | ios::binary);

    indata.read(reinterpret_cast<char *>(O), sizeof(O));

    outdata << left << setw(15) << "Radius"
            << setw(10) << "Area"
            << setw(20) << "Circumference" << endl << endl;

    for (int i = 0; i < circle_index; i++) {
        outdata << left << setw(15) << O[i].radius
                << setw(10) << O[i].area
                << setw(20) << O[i].circumference << endl;
    }

    indata.close();
    outdata.close();

    return 0;

}

