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
  if(!sal_change_rates) {
    delete[] sal_change_rates;
    sal_change_rates = nullptr;
  }
}

Employee::Employee() {
  salary = 0.0;
  cnt_sal_changes = 10;
  work_email = "work@";
  
  // Allocate memory for 10 rates
  try {
    sal_change_rates = new double[10];
    // Initialize all rates to 0.0
    for (int i = 0; i < 10; i++) {
      sal_change_rates[i] = 0.0;
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

bool Employee::isEqual(const Employee &obj) {
  bool result = true;
  // Call parent isEqual()
  result = this->Person::isEqual(obj);

  if (this->salary != obj.salary)
    result = false;
  if (this->work_email != obj.work_email)
    result = false;
  if (this->cnt_sal_changes != obj.cnt_sal_changes) {
    result = false;
  } else { // No need to compare is count isn't equal
    for (int i = 0; i < this->cnt_sal_changes && result; i++) {
      if (this->sal_change_rates[i] != obj.sal_change_rates[i])
        result = false;
      }
  }

  return result;
}

// Clone constructor
Employee::Employee(const Employee &clone) {
  work_email = clone.work_email;
  salary = clone.salary;
  cnt_sal_changes = clone.cnt_sal_changes;

  try {
    // Allocate space for sal_change_rates
    sal_change_rates = new double[10];
    sal_change_rates = clone.sal_change_rates;

    for (int i = 0; i < 10; i++) {
      this->sal_change_rates[i] = clone.sal_change_rates[i];
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

Employee Employee::operator=(const Employee &rhs) {
  work_email = rhs.work_email;
  salary = rhs.salary;
  cnt_sal_changes = rhs.cnt_sal_changes;

  try {
    // Allocate space for sal_change_rates
    sal_change_rates = new double[10];
    sal_change_rates = rhs.sal_change_rates;

    for (int i = 0; i < 10; i++) {
      this->sal_change_rates[i] = rhs.sal_change_rates[i];
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }

  return rhs;
}

double Employee::getChangeRate(int i) const {
  if (i < 0 || i > cnt_sal_changes - 1) {
    return -1.0;
  }

  return sal_change_rates[i];
}

std::string Employee::getEmail() const { return work_email; }

void Employee::setEmail(std::string new_email) {
  work_email = std::move(new_email);
}

std::string Employee::getTypeOfObj() const { return "Employee"; }

double Employee::getSalary() const { return salary; }
int Employee::getCntSalChanges() const { return cnt_sal_changes; }

void Employee::printObj() {
  this->Person::printObj();

  std::cout << "work_email: " << this->work_email
            << "\nsalary: " << this->salary
            << "\ncnt_sal_changes: " << this->cnt_sal_changes << std::endl;

  for (int i = 0; i < cnt_sal_changes; i++) {
    std::cout << i << ": " << this->sal_change_rates[i] << std::endl;
  }
}
// End class Employee

void mixedArray(Person** &arrayPersonEmp, int numPersons, int numEmployees) {
  try {
    // Allocate space for (numPersons + numEmployees) Person pointers
    arrayPersonEmp = new (Person*[numPersons + numEmployees]);
    // Initialize numPersons Person objects
    for (int i = 0; i < numPersons; i++) {
      arrayPersonEmp[i] = new Person;
      // Set email
      arrayPersonEmp[i]->setEmail("personal@gmail.com");
    }
    // Initialize numEmployee Employee objects
    for (int i = numPersons; i < numEmployees; i++) {
      arrayPersonEmp[i] = new Employee;
      // Set email
      arrayPersonEmp[i]->setEmail("work@gmail.com");
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

void deleteMixedArray(Person** &arrayPersonEmp, int size) {
  for (int i = 0; i < size; i++) {
    // Ensure Person pointer exists
    if (arrayPersonEmp[i]) {
      // Delete Person pointer
      delete arrayPersonEmp[i];
      arrayPersonEmp[i] = nullptr;
    }
  }
  // Delete array
  if (arrayPersonEmp) {
    delete[] arrayPersonEmp;
    arrayPersonEmp = nullptr;
  }
}

}//end-of namespace NS_PersonEmployee
