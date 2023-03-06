// Allows user to create array up to 50 elements, then sort the 
// array using bubble sort, then allows the user to find an 
// element in the program via binary search. 

// Bisshoy Anwar 

#include <iostream> 
#include <array> 
#include <fstream>

using namespace std; 

void bubbleSort(int[], int);
void swap(int* a, int* b);
int binarySearch(int[], int, int);
float mean(int[], int);

int main() 
{
    int SIZE; 
    int targetVal;
    int position;
    ifstream inputFile;

    inputFile.open("arraydata");

    if (!inputFile) {
        cout << "ERROR: Could not open file!" << endl;
        exit(1);
    }

    inputFile >> SIZE;
    inputFile >> targetVal;
    int arr[SIZE];

    do 
    {
        for (int i = 0; i < 2; i++) {
            inputFile.ignore(1, '\n');
        }

        for (int i = 0; i < SIZE; i++) {
            inputFile >> arr[i];
        }

    } while (!inputFile.eof());
    
    cout << "Your unordered array is:" << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl << endl;
    
    // Bubble sort 
    bubbleSort(arr, SIZE);

    // Print array
    cout << "Your ordered array is" << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    position = (binarySearch(arr, SIZE, targetVal)) + 1;

    cout << "The number " << targetVal << " is at position " << position << endl;
    cout << "The mean value of your array is " << mean(arr, SIZE) << endl;

    inputFile.close();

    return 0;

}

void bubbleSort(int array[], int size)
{
    for (int j = size - 1; j > 0; j--)
    {
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
            }
        }
    }
}

void swap(int* a, int* b)
{
    int temp; 
    temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int array[], int size, int value)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = middle;
        }

        else if (array[middle] > value) {
            last = middle - 1;
        }

        else {
            first = middle + 1;
        }
    }

    return position;

}

float mean(int array[], int size) 
{
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return (static_cast<float>(sum) / size);

}

