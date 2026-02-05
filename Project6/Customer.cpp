/*
This file implements the Customer class.
Teagen Lee
11/4/2025
*/

#include "Customer.h"

    /** It is the defult constructor
	/* @pre None
	/* @post sets everything to 0.0 */
Customer::Customer() {
    arrivalTime = 0;
    transactionTime = 0;
    customerNumber = 0;
}

    /** It is the defult constructor
    /* @param ariveTime the arival time of the Customer
    /* @param tranTime the tansaction time of the Customer
    /* @param Number the number in line the Customer is
	/* @pre None
	/* @post sets arrivalTime = ariveTime, transactionTime = tranTime, and customerNumber = Number */
Customer::Customer(int ariveTime, int tranTime, int Number) {
    arrivalTime = ariveTime;
    transactionTime = tranTime;
    customerNumber = Number;
}
    
	/** sets the arrivalTime of the Customer
	/* @param ariveTime the arrivalTime of the Customer
	/* @pre None
	/* @post The arrivalTime is set to (ariveTime)*/
void Customer::setArrivalTime(int ariveTime) {
    arrivalTime = ariveTime;
}

    /** sets the transactionTime of the Customer
	/* @param tranTime the transactionTime of the Customer
	/* @pre None
	/* @post The transactionTime is set to (tranTime)*/
void Customer::setTransactionTime(int tranTime) {
    transactionTime = tranTime;
}

    /** sets the customerNumber of the Customer
	/* @param Number the customerNumber of the Customer
	/* @pre None
	/* @post The customerNumber is set to (Number)*/
void Customer::setCustomerNumber(int Number) {
    customerNumber = Number;
}

	/** returns the arrivalTime of the Customer
	/* @pre None
	/* @post The value returned is the arrivalTime of the Customer.*/
int Customer::getArrivalTime() {
    return arrivalTime;
}

    	/** returns the transactionTime of the Customer
	/* @pre None
	/* @post The value returned is the transactionTime of the Customer.*/
int Customer::getTransactionTime() {
    return transactionTime;
}

    	/** returns the customerNumber of the Customer
	/* @pre None
	/* @post The value returned is the customerNumber of the Customer.*/
int Customer::getCustomerNumber() {
    return customerNumber;
}