// Average monthly and total sales via pointers 

// Bisshoy Anwar 

#include <iostream> 
#include <iomanip>
#include <array>

using namespace std;

float findSum(float*, int);
float findAverage(float*, int);

int main()
{
    float *monthlySales = nullptr;
    int SIZE;

    cout << fixed << showpoint << setprecision(2);

    cout << "Please input the number of monthly sales to be input" << endl;
    cin >> SIZE;

    monthlySales = new float[SIZE];

    if (!monthlySales) {
        cout << "ERROR: Could not allocate memory!" << endl;
        exit(1);
    }

    for (int i = 0; i < SIZE; i++) {
        cout << "Please input the sales for month " << i + 1 << endl;
        cin >> *(monthlySales + i);
    }

    cout << "The total sales for the year is $" << findSum(monthlySales, SIZE) << endl;
    cout << "The average monthly sale is $" << findAverage(monthlySales, SIZE) << endl;

    delete [] monthlySales;

    return 0;

}

float findSum(float* array, int size)
{
    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += *(array + i);
    }

    return sum;

}

float findAverage(float* array, int size)
{
    return (findSum(array, size)) / size;
}

