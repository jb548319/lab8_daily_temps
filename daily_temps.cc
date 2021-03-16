/*
 *        File: daily_temps.cc
 *      Author: Jonah Brautigam
 *        Date: 3/13/2021
 * Description: Finds lowest, highest, and average temperatures for the month
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

/**
 * Gets lowest temperature
 * @param daily_low array for 30 days of low temperatures
 * @return lowest temperature of the month
*/
int lowestTemp (int daily_low[]);

/**
 * Gets highest temperature
 * @param daily_low array for 30 days of low temperatures
 * @return highest temperature of the month
*/
int highestTemp (int daily_low[]);

/**
 * Gets average of all 30 days
 * @param daily_low array for 30 days of low temperatures
 * @return average temperature
*/
double lowestAvgTemp (int daily_low[]);

int main(int argc, char const *argv[]) {

    int daily_low[30];
    ifstream ins;
    int temp;
    int count = 0;
    string file_name = "athens_low_temps.txt";

    ins.open(file_name);
    if (ins.fail())
    {
        cout << "Error: Problem opening file" << endl;
        exit(0);
    }

    ins >> temp;
    while (!ins.eof())
    {
        daily_low[count] = temp;

        ins >> temp;
        count += 1;
    }

    ins.close();

    cout << fixed << setprecision(1);

    cout << "The lowest temperature this month was " << lowestTemp (daily_low) << " degrees." << endl;

    cout << "\nThe highest temperature this month was " << highestTemp (daily_low) << " degrees." << endl;

    cout << "\nThe average low temperature this month was " << lowestAvgTemp (daily_low) << " degrees." << endl;

    return 0;
}// main

int lowestTemp (int daily_low[])
{
    int low_temp = daily_low[0];
    int get_temp;
    for (int i = 1; i < 30; i++)
    {
        get_temp = daily_low[i];

        if (get_temp < low_temp)
        {
            low_temp = get_temp;
        }
    }
    return low_temp;
}

int highestTemp (int daily_low[])
{
    int high_temp = daily_low[0];
    int get_temp;
    for (int i = 1; i < 30; i++)
    {
        get_temp = daily_low[i];

        if (get_temp > high_temp)
        {
            high_temp = get_temp;
        }
    }
    return high_temp;
}

double lowestAvgTemp (int daily_low[])
{
    int low_temp;
    int sum = 0;
    double avg_temp;
    for (int i = 0; i < 30; i++)
    {
        low_temp = daily_low[i];
        sum += low_temp;
    }
    avg_temp = double(sum) / 30.0;
    return avg_temp;
}