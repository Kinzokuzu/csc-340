#include <iostream>
#include <string>


struct StructuredPhoneNumber
{
  std::string areaCode = "000";
  std::string prefix = "000";
  std::string lineNo = "000";
};


StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_ll);

bool operator==(const StructuredPhoneNumber& lhs, const StructuredPhoneNumber& rhs);

bool test1();
bool test2();
bool test3();

bool test_operator1();
bool test_operator2();


int main()
{
  std::cout << test1() << std::endl;    
  std::cout << test2() << std::endl;    
  std::cout << test3() << std::endl;    

  std::cout << test_operator1() << std::endl;
  std::cout << test_operator2() << std::endl;

  return 0;
}


StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_ll)
{
  StructuredPhoneNumber result;
  // Negative numbers treated as "000'000'0000"
  if (phoneNum_ll < 0)
    return result;

  std::string phoneNum_string = std::to_string(phoneNum_ll);
  // Numbers not 10 digits long treated as "000'000'0000"
  if (phoneNum_string.length() != 10)
    return result;

  result.areaCode = phoneNum_string.substr(0, 3);
  result.prefix = phoneNum_string.substr(3, 3);
  result.lineNo = phoneNum_string.substr(6);

  return result;
}


bool operator==(const StructuredPhoneNumber& lhs, const StructuredPhoneNumber& rhs)
{
  bool result = true;

  if (lhs.areaCode.compare(rhs.areaCode) != 0)
    result = false;
  
  if (lhs.prefix.compare(rhs.prefix) != 0)
    result = false;
  
  if (lhs.lineNo.compare(rhs.lineNo) != 0)
    result = false;

  return result;
}

bool test1()
{
  // Comparing default construction of "000'000'0000", to constrution of
  // a number not 10-digits long, also "000'000'0000"
  StructuredPhoneNumber expected_result;
  
  return expected_result == phoneNumBreakdown(13);
}

bool test2()
{
  StructuredPhoneNumber expected_result;
  expected_result.areaCode = "123";
  expected_result.prefix = "456";
  expected_result.lineNo = "7890";

  return expected_result == phoneNumBreakdown(1234567890);
}

bool test3()
{
  // Comparing default construction of "000'000'0000", to construction of
  // a negative number, also "000'000'0000"
  StructuredPhoneNumber expected_result;

  return expected_result == phoneNumBreakdown(-1234567890);
}


bool test_operator1()
{
  StructuredPhoneNumber lhs_test;
  lhs_test.areaCode = "098";
  lhs_test.prefix = "765";
  lhs_test.lineNo = "4321";

  StructuredPhoneNumber rhs_test;
  rhs_test.areaCode = "098";
  rhs_test.prefix = "765";
  rhs_test.lineNo = "4321";

  return lhs_test == rhs_test;
}

bool test_operator2()
{
  StructuredPhoneNumber lhs_test;
  StructuredPhoneNumber rhs_test;

  return lhs_test == rhs_test;
}