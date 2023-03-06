#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

float findAvg(vector<float>); 
float findHighest(vector<float> vect);
float findLowest(vector<float> vect);

int main() 
{
    int days;
    int temp;
    vector<float> temperatures;

    cout << "Please input the number of temperatures to be read" << endl;
    cin >> days;

    for (int i = 0; i < days; i++) {
        cout << "Enter temp for Day " << (i + 1) << ": ";
        cin >> temp;
        temperatures.push_back(temp);
    }

    cout << fixed << setprecision(2) << endl;
    cout << "The average temperature was: " << findAvg(temperatures) << endl;
    cout << "The highest temperature was: " << findHighest(temperatures) << endl;
    cout << "The lowest temperature was: " << findLowest(temperatures) << endl;

    return 0;

}

float findAvg(vector<float> vect) 
{
    float sum = 0;

    for (int i = 0; i < vect.size(); i++) {
        sum += vect[i];
    }

    return (sum / vect.size());

}

float findHighest(vector<float> vect)
{
    float highest = 0.0;
    
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] > highest) {
            highest = vect[i];
        }
    }

    return highest;

}

float findLowest(vector<float> vect)
{
    float lowest = 1000.0;
    
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] < lowest) {
            lowest = vect[i];
        }
    }

    return lowest;
    
}