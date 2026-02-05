/*
This file creates the WaitLine class.
dj5172pl Teagen Lee
11/4/2025
Dr. Jie Hu Meichsner
*/

#ifndef WAITLINE_H
#define WAITLINE_H

#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include "Customer.h"
#include "LinkedQueue.h"

class WaitLine
{
public:

            /** Constructor; 
    /* It is the defult constructor
	/* @pre None
	/* @post sets everything to 0.0 */
    WaitLine();  
    
            /**MEMBER FUNCTIONS*/
	/** Runs the simulation of random customers going in a line at a bank
	/* @param duration is how long the simulation runs
    /* @param arrivalProbability is how often a customer will show up
    /* @param maxTransactionTime how long a transaction can take
	/* @pre None
	/* @post The simulation is ran and outputs what happens at each time interval*/
    void simulate(int duration, double arrivalProbability, int maxTransactionTime); 

    /** Displays the final stats from the simulation
	/* @pre None
	/* @post Outputs the final stats from the simulation*/
    void displayResults(); 

private:
    // variable that makes a line for customers to join and leave.
    LinkedQueue<Customer> line;

    // the number of people who arrived
    int numberOfArrivals;   

    // the total number of people that were helped during the timeframe
    int numberServed;

    // The total time that customers waited in the line
    int totalTimeWaited;
};

#include "WaitLine.cpp"
#endif
