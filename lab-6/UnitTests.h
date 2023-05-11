//
//  UnitTests.h
//  InheritancePolymorphism-codingLab
//
//  Created by xyz on dmy.
//

#ifndef UnitTests_h
#define UnitTests_h

#include "Person.h"
#include "Employee.h"

namespace NS_UTESTS{
using namespace NS_PersonEmployee;

//Let's follow the CPP core guideline and implement each unit test as an inline
//function.
//Here's an example:
inline
bool inline_example(){
     //a few lines of code
    return true;
}

//include the following unit tests for Person class.

//bool test_PersonDCon(); //test the default constructor Person
inline
bool test_PersonDCon() {
  bool result = true;

  Person person1;
  if (person1.getSSN() != 0)
    result = false;
  if (person1.getName() != "na")
    result = false;
  if (person1.getEmail() != "personal@")
    result = false;
  if (person1.getCntPlace() != 10)
    result = false;

  // Checking each initialized place visited
  for (int i = 0; i < person1.getCntPlace() && result; i++) {
    if (person1.getPlace(i) != "unknown")
      result = false;
  }

  return result;
}

//bool test_PersonCCon();  //test the copy constructor of Person
inline
bool test_PersonCCon() {
  Person person1;
  person1.setEmail("test@mail");
  Person person2(person1);

  return person2.isEqual(person1);
}

//bool test_PersonCAssign(); //test the copy assignment operator of Person
inline
bool test_PersonCAssign() {
  Person person1;
  person1.setEmail("test@mail");
  Person person2 = person1;

  return person2.isEqual(person1);
}

//include the following unit tests for Employee class.

//bool test_EmployeeDCon(); //test the default constructor Employee
inline
bool test_EmployeeDCon() {
  bool result = true;

  Employee employee1;
  if (employee1.getEmail() != "work@")
    result = false;
  if (employee1.getSalary() != 0.0)
    result = false;
  if (employee1.getCntSalChanges()!= 10)
    result = false;

  // Checking each initialized sal_change_rate
  for (int i = 0; i < employee1.getCntSalChanges() && result; i++) {
    if (employee1.getChangeRate(i) != 0.0)
      result = false;
  }

  return result;
}

//bool test_EmployeeCCon();  //test the copy constructor of Employee
inline
bool test_EmployeeCCon() {
  Employee employee1;
  employee1.setEmail("test@mail");
  Employee employee2(employee1);

  return employee2.isEqual(employee1);
}

//bool test_EmployeeCAssign(); //test the copy assignment operator of Employee
inline
bool test_EmployeeCAssign() {
  Employee employee1;
  employee1.setEmail("test@mail");
  Employee employee2 = employee1;

  return employee2.isEqual(employee1);
}

//bool test_mixedArray(); //test the free-standing function mixedArray()
bool test_mixedArray() {
  bool result = true;

  // Declare and initialize mixedArray
  int numPersons = 1;
  int numEmployees = 1;
  Person** arrayPersonEmp;
  mixedArray(arrayPersonEmp, numPersons, numEmployees);

  int personCount = 0;
  for (int i = 0; i < numPersons + numEmployees; i++) {
    if (arrayPersonEmp[i]->getEmail() == "personal@gmail.com")
      personCount++;
  }

  int employeeCount = 0;
  for (int i = 0; i < numPersons + numEmployees; i++) {
    if (arrayPersonEmp[i]->getEmail() == "work@gmail.com")
      employeeCount++;
  }

  if (personCount != numPersons)
    result = false;

  if (employeeCount != numEmployees)
    result = false;

  deleteMixedArray(arrayPersonEmp, numPersons + numEmployees);

  return result;
}

}//end-of namespace NS_UTESTS

#endif /* UnitTests_h */
