/*
This file impelments the NotFoundException error.
dj5172pl Teagen Lee
Due: 11/4/2025
Dr. Jie Hu Meichsner
*/


//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.cpp */
#include "NotFoundException.h"  

NotFoundException::NotFoundException(const std::string& message)
      : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

