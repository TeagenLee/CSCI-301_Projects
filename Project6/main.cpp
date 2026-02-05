/*
Runs a simulation of a waiting line that customers join, and then after they are helped
they then leave the line.
dj5172pl Teagen Lee
11/4/2025
Dr. Jie Hu Meichsner
*/

#include "WaitLine.h"
#include <iostream>
using namespace std;

int main()
{
    int duration;
    double arrivalProbability;
    int maxTransactionTime;

    cout << "Enter the total simulation time (minutes): ";
    cin >> duration;

    cout << "Enter the arrival probability (0 to 1): ";
    cin >> arrivalProbability;

    cout << "Enter the maximum transaction time (minutes): ";
    cin >> maxTransactionTime;

    WaitLine simulation; // Fixed variable name to lowercase
    simulation.simulate(duration, arrivalProbability, maxTransactionTime); // Call simulate

    return 0;
}
