/*
The goal of this program is to calculate simple expressions given by the user. The program has many checks to make sure the
expression entered is formatted correctly.
Teagen Lee
Due: 10/24/2025
*/

#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedStack.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include "InfixCalculator.h"

using namespace std;

int main() {
    InfixCalculator calc;
    string expr;

    cout << "    Simple Infix Calculator    " << endl;
    cout << "Allowed: single digits (0-9), operators (+ - * /), parentheses ()." << endl << endl;
   
    cout << "Enter expression: ";
    getline(cin, expr);

    if (!calc.setExpression(expr)) {
        return 1;
    }

    try {
        int result = calc.evaluate();
        cout << "Result: " << result << endl << endl;
    } 
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl << endl;
    }


    return 0;
}
