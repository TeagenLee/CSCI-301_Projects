/*
This file implements the WaitLine class.
dj5172pl Teagen Lee
11/4/2025
Dr. Jie Hu Meichsner
*/

#include "WaitLine.h"
using namespace std;

    /* It is the defult constructor
	/* @pre None
	/* @post sets everything to 0.0 */
WaitLine::WaitLine()
{
    numberOfArrivals = 0;  
    numberServed = 0;
    totalTimeWaited = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
}

	/** Runs the simulation of random customers going in a line at a bank
	/* @param duration is how long the simulation runs
    /* @param arrivalProbability is how often a customer will show up
    /* @param maxTransactionTime how long a transaction can take
	/* @pre None
	/* @post The simulation is ran and outputs what happens at each time interval*/
void WaitLine::simulate(int duration, double arrivalProbability, int maxTransactionTime)
{
    int transactionTimeLeft = 0; // Time left for current customer

    for (int clock = 0; clock < duration; clock++)
    {
        cout << "Time " << clock << ":";

        // Random check for new arrival
        double randomValue = static_cast<double>(rand()) / RAND_MAX;
        if (randomValue < arrivalProbability)
        {
            numberOfArrivals++;
            int transactionTime = rand() % maxTransactionTime + 1; // Random transaction time from 1 to max
            Customer nextCustomer(clock, transactionTime, numberOfArrivals);
            line.enqueue(nextCustomer);
            cout << "\tCustomer " << numberOfArrivals
                 << " enters line with a " << transactionTime
                 << "-minute transaction.\n";
        }
        else
        {
            cout << "\n"; // no new customer
        }

        // Serve current customer
        if (transactionTimeLeft > 0)
        {
            cout << "\tCustomer being served continues (" << transactionTimeLeft << " min left).\n";
            transactionTimeLeft--;
        }
        else if (!line.isEmpty())  // Check if line is not empty
        {
            Customer nextCustomer = line.peekFront();  // Peek front
            line.dequeue();                            // Remove from queue

            int timeWaited = clock - nextCustomer.getArrivalTime();
            totalTimeWaited += timeWaited;
            numberServed++;

            transactionTimeLeft = nextCustomer.getTransactionTime() - 1; // Serving starts now

            cout << "\tCustomer " << nextCustomer.getCustomerNumber()
                 << " begins service after waiting " << timeWaited << " minutes.\n";
        }
    }

    cout << "\nSimulation ends.\n";
    displayResults();
}

    /** Displays the final stats from the simulation 
	/* @pre None
	/* @post Outputs the final stats from the simulation*/
void WaitLine::displayResults()
{
    cout << "The final statistics:\n";
    cout << "  Total number of customers served: " << numberServed << endl;

    if (numberServed > 0)
    {
        double averageWait = static_cast<double>(totalTimeWaited) / numberServed;
        cout << "  Average amount of time spent waiting: " << averageWait << " minutes\n";
    }
    else
    {
        cout << "  No customers were served.\n";
    }

    // LinkedQueue does not have size(), so count manually
    int remaining = 0;
    LinkedQueue<Customer> tempQueue = line; // Copy queue
    while (!tempQueue.isEmpty())
    {
        tempQueue.dequeue();
        remaining++;
    }

    cout << "  Number of customers left in line: " << remaining << endl;
}
