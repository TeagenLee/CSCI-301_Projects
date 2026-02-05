/*
This file tests the FrontListIsA class
dj5172pl Teagen Lee
Due: 11/17/2025
Dr. Jie Hu Meichsner
*/

#include <iostream>
#include <string>
#include <memory>

#include "FrontListIsA.h"

int main()
{
    std::shared_ptr<FrontListIsA<std::string>> fl = std::make_shared<FrontListIsA<std::string>>();

    std::cout << "Testing FrontListIsA (public inheritance)\n";

    fl->insert("one");
    fl->insert("two");
    fl->insert("three");

    std::cout << "Length (via inherited getLength): " << fl->getLength() << std::endl;
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

    // Test disabled operations: should return false or throw
    bool res = fl->insert(2, "bad");
    std::cout << "Attempt insert(pos, item) (should be disabled => 0): " << res << std::endl;

    try {
        fl->replace(1, "bad");
    } catch (PrecondViolatedExcept& e) {
        std::cout << "replace(...) threw as expected: " << e.what() << std::endl;
    }

    return 0;
}
