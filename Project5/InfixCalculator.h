/*
This file creates the InfixClalculator class.
Teagen Lee
Due: 10/24/2025
*/


#ifndef INFIX_CALCULATOR_H
#define INFIX_CALCULATOR_H

#include "LinkedStack.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <string>

using namespace std;

class InfixCalculator {
private:
    string infixExpr;

        /** CONSTANT MEMBER FUNCTIONS*/
	/** Checks to see if the expression is well formated
	/* @param expr the expression being checked for correctness
    /* @pre None
	/* @post The value returned is a true or false.*/
    bool isWellFormed(const string& expr) const;

	/** Checks to see if the expression has balenced parenthesies
	/* @param expr the expression being checked for correctness
    /* @pre None
	/* @post The value returned is a true or false.*/
    bool isBalanced(const string& expr) const;

	/** Takes an algebraic expression and turns it into a postfix expression
	/* @param expr the expression being changed
    /* @pre None
	/* @post The value returned is a the postfix expression.*/
    string infixToPostfix(const string& expr) const;

    /** Determines what operand have higher precedence.
    /* @param op the character being checked.
    /* @pre None
	/* @post The value retured shows if op has precedence or not.*/
    int precedence(char op) const;

    /** Calculates the result of the algebraic expression.
    /* @param postfix the expression being calculated.
    /* @pre postfix needs to be a postfix expression
	/* @post The value retured is the result of the algebraic expression.*/
    int evaluatePostfix(const string& postfix) const;

public:
        /** MODIFICATION MEMBER FUNCTIONS*/
	/** Checks to make sure expression meets all requirments
	/* @param expr the expression being evaluated.
	/* @pre None
	/* @post The value returned is a true or false depending on if it passes or fails*/
    bool setExpression(const string& expr);

	/** Calculates the algebraic expression given by teh user and solves it.
	/* @param expr the expression being evaluated.
	/* @pre None
	/* @post The value returned is the calculated result. */
    int evaluate() const;
};

#include "InfixCalculator.cpp"
#endif
