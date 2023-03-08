// This program does plane stuff

// Bisshoy Anwar 

#include <iostream>

using namespace std;

struct planeStats
{
    int landed;
    int departed;
    int greatestPlanes;
    int leastPlanes;
};

const int SIZE = 12;
string months[SIZE] = {"January", "February", "March", "April", 
                         "May", "June", "July", "August", "September", 
                         "October", "November", "December"};

void getPlaneStats(planeStats*, int);

int main()
{
    planeStats arr[SIZE];

    getPlaneStats(arr, SIZE);

    int totalLanded = 0;
    int totalDeparted = 0;
    int greatestLanded = 0;
    int fewestLanded = 0;

    for (int i = 0; i < SIZE; i++) {
        totalLanded += arr[i].landed;
        totalDeparted += arr[i].departed;

        if (i != 0) {
            if (arr[i].greatestPlanes > arr[greatestLanded].greatestPlanes) {
                greatestLanded = i;
            }

            if (arr[i].leastPlanes < arr[fewestLanded].leastPlanes) {
                fewestLanded = i;
            }
        }

    }

    cout << "Total planes landed in year: " << totalLanded << endl;
    cout << "Average planes landed per month: " << (static_cast<float>(totalLanded) / SIZE) << endl;

    cout << "Total planes departed in year: " << totalDeparted << endl;
    cout << "Average planes departed per month: " << (static_cast<float>(totalDeparted) / SIZE) << endl;

    cout << "Most planes landed in a day: " << arr[greatestLanded].greatestPlanes << endl;
    cout << "Fewest planes landed in a day: " << arr[fewestLanded].leastPlanes << endl;

    return 0;

}

void getPlaneStats(planeStats* ex, int m)
{

    for (int i = 0; i < m; i++) {
        cout << "Enter the total number of planes that landed in " << months[i] << ": ";
        cin >> ex->landed;

        cout << "Enter the total number of planes that departed in " << months[i] << ": ";
        cin >> ex->departed;

        cout << "Enter the most planes that landed in " << months[i] << ": ";
        cin >> ex->greatestPlanes;

        cout << "Enter the fewest planes that landed in " << months[i] << ": ";
        cin >> ex->leastPlanes;

        ex++;

        cout << endl;

    }

}

