/*
This file tests the FrontListAsA class
Teagen Lee
Due: 11/17/2025
*/


#include <iostream>
#include <string>
#include <memory>

#include "FrontListAsA.h"

int main()
{
    std::shared_ptr<FrontListAsA<std::string>> fl = std::make_shared<FrontListAsA<std::string>>();

    std::cout << "Testing FrontListAsA (private inheritance)\n";

    fl->insert("alpha");
    fl->insert("beta");
    fl->insert("gamma");

    std::cout << "Length: " << fl->getLength() << std::endl;
    std::cout << "Front: " << fl->retrieve() << std::endl;

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
