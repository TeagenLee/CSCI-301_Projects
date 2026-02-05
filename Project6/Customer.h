/*
This file creates the Customer class.
Teagen Lee
Due: 11/4/2025
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    public:
            /** Constructor; 
    /* It is the defult constructor
	/* @pre None
	/* @post sets everything to 0.0 */
    Customer();

    /** It is the defult constructor
    /* @param ariveTime the arival time of the Customer
    /* @param tranTime the tansaction time of the Customer
    /* @param Number the number in line the Customer is
	/* @pre None
	/* @post sets arrivalTime = ariveTime, transactionTime = tranTime, and customerNumber = Number */
    Customer(int ariveTime, int tranTime, int Number);
    
            /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the arrivalTime of the Customer
	/* @param ariveTime the arrivalTime of the Customer
	/* @pre None
	/* @post The arrivalTime is set to (ariveTime)*/
    void setArrivalTime(int ariveTime);

    /** sets the transactionTime of the Customer
	/* @param tranTime the transactionTime of the Customer
	/* @pre None
	/* @post The transactionTime is set to (tranTime)*/
    void setTransactionTime(int tranTime);

    /** sets the customerNumber of the Customer
	/* @param Number the customerNumber of the Customer
	/* @pre None
	/* @post The customerNumber is set to (Number)*/
    void setCustomerNumber(int Number);

            /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the arrivalTime of the Customer
	/* @pre None
	/* @post The value returned is the arrivalTime of the Customer.*/
    int getArrivalTime();

    	/** returns the transactionTime of the Customer
	/* @pre None
	/* @post The value returned is the transactionTime of the Customer.*/
    int getTransactionTime();

    	/** returns the customerNumber of the Customer
	/* @pre None
	/* @post The value returned is the customerNumber of the Customer.*/
    int getCustomerNumber();

    private:
    // variable storing when the customer arrives
    int arrivalTime;
    
    // variable storing how long the transaction will take
    int transactionTime;

   // variable storing the customer's number in the line
    int customerNumber;
};

#include "Customer.cpp"
#endif