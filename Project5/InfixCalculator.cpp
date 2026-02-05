/*
This file implements the InfixClalculator class.
Teagen Lee
Due: 10/24/2025
*/


#include "InfixCalculator.h"
#include "LinkedStack.h"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>

using namespace std;

/** Checks to see if the expression is well formated
	/* @param expr the expression being checked for correctness
    /* @pre None
	/* @post The value returned is a true or false.*/
bool InfixCalculator::isWellFormed(const string& expr) const {
    if (expr.empty()) return false;

    enum Token { NONE, OPERAND, OPERATOR, OPEN, CLOSE };
    Token prev = NONE;

    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (isdigit(static_cast<unsigned char>(c))) {
            if (prev == OPERAND) return false; // multi-digit
            prev = OPERAND;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (i == 0 || prev == OPERATOR || prev == OPEN || prev == NONE) return false;
            prev = OPERATOR;
        } else if (c == '(') {
            if (prev == OPERAND || prev == CLOSE) return false;
            prev = OPEN;
        } else if (c == ')') {
            if (prev == OPERATOR || prev == OPEN || prev == NONE) return false;
            prev = CLOSE;
        } else {
            return false;
        }
    }
    if (prev == OPERATOR || prev == OPEN) return false;
    return true;
}

    /** Checks to see if the expression has balenced parenthesies
	/* @param expr the expression being checked for correctness
    /* @pre None
	/* @post The value returned is a true or false.*/
bool InfixCalculator::isBalanced(const string& expr) const {
    LinkedStack<char> st;
    for (char c : expr) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.isEmpty()) return false;
            st.pop();
        }
    }
    return st.isEmpty();
}

    /** Determines what operand have higher precedence.
    /* @param op the character being checked.
    /* @pre None
	/* @post The value retured shows if op has precedence or not.*/
int InfixCalculator::precedence(char op) const {
    switch (op) {
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

    /** Takes an algebraic expression and turns it into a postfix expression
	/* @param expr the expression being changed
    /* @pre None
	/* @post The value returned is a the postfix expression.*/
string InfixCalculator::infixToPostfix(const string& expr) const {
    LinkedStack<char> ops;
    ostringstream out;

    for (char c : expr) {
        if (isdigit(static_cast<unsigned char>(c))) {
            out << c << ' ';
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                out << ops.peek() << ' ';
                ops.pop();
            }
            if (ops.isEmpty()) throw runtime_error("Unmatched parentheses.");
            ops.pop();
        } else {
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(c)) {
                if (ops.peek() == '(') break;
                out << ops.peek() << ' ';
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.isEmpty()) {
        char top = ops.peek();
        if (top == '(' || top == ')') throw runtime_error("Unbalanced parentheses.");
        out << top << ' ';
        ops.pop();
    }

    return out.str();
}

    /** Calculates the result of the algebraic expression.
    /* @param postfix the expression being calculated.
    /* @pre postfix needs to be a postfix expression
	/* @post The value retured is the result of the algebraic expression.*/
int InfixCalculator::evaluatePostfix(const string& postfix) const {
    LinkedStack<int> values;
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        if (token.size() == 1 && isdigit(static_cast<unsigned char>(token[0]))) {
            values.push(token[0] - '0');
        } else if (token.size() == 1 && string("+-*/").find(token[0]) != string::npos) {
            if (values.isEmpty()) throw runtime_error("Missing operand.");
            int b = values.peek(); values.pop();
            if (values.isEmpty()) throw runtime_error("Missing operand.");
            int a = values.peek(); values.pop();
            int r = 0;
            switch (token[0]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) throw runtime_error("Division by zero.");
                    r = a / b;
                    break;
            }
            values.push(r);
        } else {
            throw runtime_error("Invalid token in postfix.");
        }
    }

    if (values.isEmpty()) throw runtime_error("Empty postfix expression.");
    int result = values.peek();
    values.pop();
    if (!values.isEmpty()) throw runtime_error("Extra operands.");
    return result;
}

    /** Checks to make sure expression meets all requirments
	/* @param expr the expression being evaluated.
	/* @pre None
	/* @post The value returned is a true or false depending on if it passes or fails*/
bool InfixCalculator::setExpression(const string& expr) {
    if (expr.empty()) {
        cerr << "[Error] Expression cannot be empty." << endl;
        return false;
    }

    if (expr.find(' ') != string::npos) {
        cerr << "[Error] Expression must not contain spaces." << endl;
        return false;
    }

    for (char c : expr) {
        if (!isdigit(static_cast<unsigned char>(c)) &&
            string("+-*/()").find(c) == string::npos) {
            cerr << "[Error] Invalid character detected: '" << c << endl;
            return false;
        }
    }

    if (!isWellFormed(expr)) {
        cerr << "[Error] Expression is not well formed." << endl;
        return false;
    }

    if (!isBalanced(expr)) {
        cerr << "[Error] Expression has unbalanced parentheses." << endl;
        return false;
    }

    infixExpr = expr;
    return true;
}

    /** Calculates the algebraic expression given by teh user and solves it.
	/* @param expr the expression being evaluated.
	/* @pre None
	/* @post The value returned is the calculated result. */
int InfixCalculator::evaluate() const {
    if (infixExpr.empty()) throw runtime_error("No expression set.");
    string postfix = infixToPostfix(infixExpr);
    return evaluatePostfix(postfix);
}
