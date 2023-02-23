#include <iostream>
#include <string>


struct StructuredPhoneNumber
{
  std::string areaCode = "000";
  std::string prefix = "000";
  std::string lineNo = "000";
};

/*
void PrintStuct(StructuredPhoneNumber input)
{
  std::cout << "Area Code: " << input.areaCode << std::endl;
  std::cout << "Prefix: " << input.prefix << std::endl;
  std::cout << "LineNo: " << input.lineNo << std::endl;
}
*/

StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_ll);

bool operator==(StructuredPhoneNumber lhs, StructuredPhoneNumber rhs);

//bool test1();
//bool test2();
//bool test3();

bool test_operator1();
//bool test_operator2();

int main()
{
  StructuredPhoneNumber test = phoneNumBreakdown(9254830830);
  std::cout << test_operator1() << std::endl;
  
  return 0;
}


StructuredPhoneNumber phoneNumBreakdown(long long phoneNum_ll)
{
  StructuredPhoneNumber result;

  if (phoneNum_ll < 0)
    return result;

  std::string phoneNum_string = std::to_string(phoneNum_ll);

  if (phoneNum_string.length() != 10)
    return result;

  result.areaCode = phoneNum_string.substr(0, 3);
  result.prefix = phoneNum_string.substr(3, 3);
  result.lineNo = phoneNum_string.substr(6);

  return result;
}

// FIX ME
bool operator==(StructuredPhoneNumber lhs, StructuredPhoneNumber rhs)
{
  bool result = true;

  if (!lhs.areaCode.compare(rhs.areaCode))
    result = false;
  
  if (!lhs.prefix.compare(rhs.prefix))
    result = false;

  if (!lhs.lineNo.compare(rhs.lineNo))
    result = false;

  return result;
}