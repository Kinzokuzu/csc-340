//
//  Person.cpp
//  InheritancePolymorphism-codingLab
//
//  Created by ...
//

#include "Person.h"

namespace NS_PersonEmployee{

//implement each of the member functions included in the Person class
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
  return rhs;
}

Person::Person(const Person &clone) {}

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
