/*
This file creates the PrecondViolatedExcept class.
Teagen Lee
Due: 12/3/2025
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/**  @file PrecondViolatedExcept.h */

#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
   PrecondViolatedExcept(const std::string& message = "");
}; // end PrecondViolatedExcep 

#include "PrecondViolatedExcept.cpp"
#endif
