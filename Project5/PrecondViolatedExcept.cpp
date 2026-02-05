/*
This file implements the PrecondViolatedExcept error.
Teagen Lee
Due: 10/24/2025
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file PrecondViolatedExcept.cpp */

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
            : std::logic_error("Precondition Violated Exception: " + message)
{   }    // end constructor

