//
//  main.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Hui Yang on 5/4/22.
//

#include "Person.h"
#include "Employee.h"
#include "UnitTests.h"

int main(int argc, const char * argv[]) {
    using namespace NS_PersonEmployee;
   
    //call your unit tests and/or directly test your code below
    std::cout << NS_UTESTS::test_PersonDCon() << std::endl;
    std::cout << NS_UTESTS::test_PersonCCon() << std::endl;
    std::cout << NS_UTESTS::test_PersonCAssign() << std::endl;
    std::cout << NS_UTESTS::test_EmployeeDCon() << std::endl;
    std::cout << NS_UTESTS::test_EmployeeCCon() << std::endl;
    std::cout << NS_UTESTS::test_EmployeeCAssign() << std::endl;
    std::cout << NS_UTESTS::test_mixedArray() << std::endl;

    return 0;
}
