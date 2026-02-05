/*
This file tests the FrontListHasA class
dj5172pl Teagen Lee
Due: 11/17/2025
Dr. Jie Hu Meichsner
*/


#include <iostream>
#include <string>
#include <memory>

#include "FrontListHasA.h"

int main()
{
    std::shared_ptr<FrontListHasA<std::string>> fl = std::make_shared<FrontListHasA<std::string>>();

    std::cout << "Testing FrontListHasA\n";

    fl->insert("first");
    fl->insert("new first");
    fl->insert("again first");

    std::cout << "Length: " << fl->getLength() << std::endl;
    std::cout << "Front element: " << fl->retrieve() << std::endl;

    fl->remove();
    std::cout << "After remove, front: " << fl->retrieve() << std::endl;

    fl->clear();
    std::cout << "After clear, isEmpty: " << fl->isEmpty() << std::endl;

    try {
        fl->retrieve();
    } catch (PrecondViolatedExcept& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
