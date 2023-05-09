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

//Let's follow the CPP core guidline and implement each unit test as an inline
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
  if (person1.SSN != 0)
    result = false;
  if (person1.name != "na")
    result = false;
  if (person1.email != "personal@")
    result = false;
  if (person1.cntPlace != 10)
    result = false;

  // Checking each initialized place visited
  for (int i = 0; i < person1.cntPlace && result == true; i++) {
    if (person1.placesVisited[i] != "unkown")
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
  if (employee.work_email != "work@")
    result = false;
  if (employee.salary !- 0.0)
    result = false;
  if (cnt_sal_changes != 10)
    result = false;

  // Checking each initialized sal_change_rate
  for (int i = 0; i < employee1.cnt_sal_changes && result == true; i++) {
    if (employee1.sal_change_rates[i] != 0.0)
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

}//end-of namespace NS_UTESTS

#endif /* UnitTests_h */
