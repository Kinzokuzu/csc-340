#include <iostream>

#include "unitTest.h"
#include "tokenFreq.h"

int main()
{
  std::cout << NS_UNIT_TESTS::test1_matrixInit() << std::endl;
  std::cout << NS_UNIT_TESTS::test2_matrixInit() << std::endl;
  std::cout << NS_UNIT_TESTS::test3_matrixInit() << std::endl;

  std::cout << NS_UNIT_TESTS::test1_operatorLE() << std::endl;
  std::cout << NS_UNIT_TESTS::test2_operatorLE() << std::endl;
  std::cout << NS_UNIT_TESTS::test3_operatorLE() << std::endl;

  return 0;
}