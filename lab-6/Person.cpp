//
//  Person.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by Saul Cervantes-Hernandez
//  May 10, 2023

#include "Person.h"

#include <utility>

namespace NS_PersonEmployee{

//implement each of the member functions included in the Person class
Person::~Person() {
  if (!placesVisited) {
    delete[] placesVisited;
    placesVisited = nullptr;
  }
}
  
Person::Person() {
  SSN = 0;
  name = "na";
  personalEmail = "personal@";
  cntPlaces = 10;
  // Allocate memory for cntPlaces places
  try {
    placesVisited = new std::string[cntPlaces];
    // Initialization of each place to "unknown"
    for (int i = 0; i < cntPlaces; i++) {
      placesVisited[i] = "unknown";
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

bool Person::isEqual(const Person &obj) {
  bool result = true;
  
  // Compare each field in Person
  if (this->SSN != obj.SSN)
    result = false;
  if (this->name != obj.name)
    result = false;
  if (this->personalEmail != obj.personalEmail)
    result = false;
  if (this->cntPlaces != obj.cntPlaces) {
    result = false;
  } else { // No need to compare if count isn't equal
    for (int i = 0; i < this->cntPlaces && result; i++) {
      if (this->placesVisited[i] != obj.placesVisited[i])
        result = false;
    }
  }

  return result;
}
// FIX ME: Return type should be Person
Person Person::operator=(const Person& rhs) {
  SSN = rhs.SSN;
  name = rhs.name;
  personalEmail = rhs.personalEmail;
  cntPlaces = rhs.cntPlaces;

  try {
    // Delete old placesVisited
    delete[] placesVisited;
    // Allocate space for new placesVisited
    placesVisited = new std::string[rhs.cntPlaces];
    for (int i = 0; i < rhs.cntPlaces; i++) {
      this->placesVisited[i] = rhs.placesVisited[i];
    }
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }

  return rhs;
}

// Copy constructor
Person::Person(const Person &clone) {
  SSN = clone.SSN;
  name = clone.name;
  personalEmail = clone.personalEmail;
  cntPlaces = clone.cntPlaces;

  try {
    // Allocate space for new placesVisited
    placesVisited = new std::string[clone.cntPlaces];
    placesVisited = clone.placesVisited;
  } catch (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}

std::string Person::getPlace(int i ) const {
  // Check if 'i' is a valid member of placesVisited
  if (i < 0 || i > cntPlaces - 1) {
    return "out-of-boundary";
  }

  return placesVisited[i];
}

std::string Person::getEmail() const { return personalEmail; }

void Person::setEmail(std::string new_email) {
  personalEmail = std::move(new_email);
}

std::string Person::getTypeOfObj() const { return "Person"; }

int Person::getSSN() const { return SSN; }
std::string Person::getName() const { return name; }
int Person::getCntPlace() const { return cntPlaces; }

void Person::printObj() const {
  std::cout << "SSN: " << this->SSN
            << "\nname: " << this->name
            << "\npersonalEmail: " << this->personalEmail
            << "\ncntPlaces: " << this->cntPlaces << std::endl;

  for (int i = 0; i < this->cntPlaces; i++) {
    std::cout << i << ": " << this->placesVisited[i] << std::endl;
  }
}

}//end-of namespace NS_PersonEmployee
