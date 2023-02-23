/* Project Description
Given a long long integer representing a 10-dgit phone number, write a
function to segment this number into
  • a three-digit area code
  • a three-digit prefix
  • a four-digit number
Ex: If the input is:
  8005551212
It will be segmented into: 800, 555, and 1212.
*/

/* Deliverables
1) A desgin doc in the file DesignDoc.h.  The contnet has to be included
   as comments.  Your program will not compile otherwise.
2) Unit tests included as part of your program file.
3) Your C++ program file.  DO NOT include "using namespace std;" in the
   global scope.
4) Code review by yourself and by a peer by following the guideline
   checklist.
*/

/* Declarations
struct StructuredPhoneNumber
{
  std::string areaCode = "000"; // 3 digits
  std::string prefix = "000";   // 3 digits
  std::string lineNo = "0000";  // 4 digits
};

Converts a phone number from a 10-digit long long to {area code, prefix,
lineNo}.
Returns a StructuredPhoneNumber object {"000", "000", "0000"} if the
input number is a negative or less than 10 digits.
StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_11);

Overload operator==() as a free-standing function to compare whether two
StructuredPhoneNumber objects contain exactly the same phone number.
*/

/* Algorithm Design

*/