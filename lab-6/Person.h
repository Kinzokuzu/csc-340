//
//  Created by ... on ...
//

#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
#include <new>

namespace NS_PersonEmployee{

using namespace std;

class Person{
public:
    //******************Note*********
    //This interface is by no means complete.  Please feel free to
    // add more functions if needed. The test cases however will only
    // test the following functions.
    //
    virtual ~Person();
    Person(); //0->SSN, "na"->name, "personal@"->personalEmail, 10->cntPlaces,
              //allocate space to placesVisited and initializes each place to
              //"unknown"
              
    // Used to compare two Person obj    
    bool isEqual(const Person &obj);
    // FIX ME: Return type should be Person    
    Person operator=(const Person& rhs );
    //copy constructor
    Person( const Person &clone );
    
    string getPlace(int i) const; //return the i-th place in the placesVisited
                                  //array if i is valid; otherwise return
                                  //"out-of-boundary".

    virtual string getEmail() const; //return personalEmail
    virtual void setEmail( string new_email); //new_email-->personalEmail
    virtual string getTypeOfObj() const; //return "Person"

    int getSSN() const;
    string getName() const;
    int getCntPlace() const;

    virtual void printObj() const;

private:
    int SSN;
    string name;
    string personalEmail;

    string *placesVisited;
    int cntPlaces; //companion variable of the above pointer
};

}//namespace NS_PersonEmployee

#endif /* Person_h */

