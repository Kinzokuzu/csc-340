//
//  Person.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by ...
//

#include "Person.h"

namespace NS_PersonEmployee{

//implement each of the member functions included in the Person class
bool Person::isEqual(const Person &obj) {
  bool result = true;

  if (this->SSN != obj.SSN)
    result = false;
  if (this->name != obj.name)
    result = false;
  if (this->personalEmail != obj.personalEmail)
    result = false;
  if (this->cntPlaces != obj.cntPlaces) {
    result = false;
  } else {
    for (int i = 0; i < this->cntPlaces; i++) {
      if (this->placesVisited[i] != obj.placesVisited[i])
        result = false;
    }
  }

  return result;
}

Person::~Person() {
  delete[] placesVisited;
}
  
Person::Person() {
  SSN = 0;
  name = "na";
  personalEmail = "personal@";
  cntPlaces = 10;
  placesVisited = new std::string[cntPlaces];
  
  // Initialization of each place to "unkown"
  for (int i = 0; i < cntPlaces; i++) {
    placesVisited[i] = "unkown";
  }
}

Person Person::operator=(const Person& rhs) {
  // DO NOT self-assign
  if (!this->isEqual(rhs)) {
    SSN = rhs.SSN;
    name = rhs.name;
    personalEmail = rhs.personalEmail;
    cntPlaces = rhs.cntPlaces;

    // Delete old placesVisited
    delete[] placesVisited;
    // Allocate space for new placesVisited
    placesVisited = new std::string[rhs.cntPlaces];
    placesVisited = rhs.placesVisited;
  }
}

// Copy constructor
Person::Person(const Person &clone) {
  SSN = clone.SSN;
  name = clone.name;
  personalEmail = clone.personalEmail;
  cntPlaces = clone.cntPlaces;

  // Delete old placesVisited
  delete[] placesVisited;
  // Allocate space for new placesVisited
  placesVisited = new std::string[clone.cntPlaces];
  placesVisited = clone.placesVisited;
}

std::string Person::getPlace(int i ) const {
  // Check if 'i' is a valid memeber of placesVisited
  if (i < 0 || i > cntPlaces - 1) {
    return "out-of-boundary";
  }

  return placesVisited[i];
}

std::string Person::getEmail() const { return personalEmail; }

void Person::setEmail(std::string new_email) { personalEmail = new_email; }

std::string Person::getTypeOfObj() const { return "Person"; }

}//end-of namespace NS_PersonEmployee
