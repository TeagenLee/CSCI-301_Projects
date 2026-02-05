/*
This file implements the PrecondViolatedExcept class.
dj5172pl Teagen Lee
13/3/2025
Dr. Jie Hu Meichsner
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file PrecondViolatedExcept.cpp */

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
            : std::logic_error("Precondition Violated Exception: " + message)
{   }    // end constructor

