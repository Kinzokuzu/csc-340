//
//  Employee.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Saul Cervantes-Hernandez on May 10, 2023
//


#include "Employee.h"

namespace NS_PersonEmployee{

//implement Employee's member functions and the two free-standing functions
//below
Employee::~Employee() {
  delete[] sal_change_rates;
}

Employee::Employee() {
  salary = 0.0;
  cnt_sal_changes = 10;
  work_email = "work@";
  
  // Allocate memroy for 10 rates
  sal_change_rates = new double[10];
  // Initialize all rates to 0.0
  for (int i = 0; i < 10; i++) {
    sal_change_rates[i] = 0.0;
  }
}

bool Employee::isEqual(const Employee &obj) {
  bool result = true;
  // Call parant isEqual()
  result = this->Person::isEqual(obj);

  if (this->salary != obj.salary)
    result = false;
  if (this->work_email != obj.work_email)
    result = false;
  if (this->cnt_sal_changes != obj.cnt_sal_changes) {
    result = false;
  } else { // No need to compare is count isn't equal
    for (int i = 0; i < this->cnt_sal_changes && result == true; i++) {
      if (this->sal_change_rates[i] != obj.sal_change_rates[i])
        result = false;
      }
  }

  return result;
}

// Clone constructor
// Employee::Employee(const Employee &clone) {}

// Employee Employee::operator=(const Employee &rhs) {}

double Employee::getChangeRate(int i) const { return sal_change_rates[i]; }

std::string Employee::getEmail() const { return work_email; }

void Employee::setEmail(std::string new_email) {
  work_email = new_email;
}

std::string Employee::getTypeOfObj() const { return "Employee"; }

void Employee::printObj() {
  this->Person::printObj();

  std::cout << "work_email: " << this->work_email
            << "\nsalaray: " << this->salary
            << "\ncnt_sal_changes: " << this->cnt_sal_changes << std::endl;

  for (int i = 0; i < cnt_sal_changes; i++) {
    std::cout << i << ": " << this->sal_change_rates[i] << std::endl;
  }
}
// End class Employee

// void mixedArray(Person** &arrayPersonEmp, int numPersons, int numEmployees) {}

// void deleteMixedArray(Person** &arrayPersonEmp, int size) {}

}//end-of namespace NS_PersonEmployee
