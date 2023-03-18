#include <vector>

#include "matrixInit.h"
#include "tokenFreq.h"

namespace NS_UNIT_TESTS
{
  // Initialization of a 0 x 0 matrix.
  bool test1_matrixInit()
  {
    std::vector<std::vector<int>> matrix;
    NS_MATRIX::matrixInit(matrix, 0, 0);

    // If there are 0 rows, then there are automatically 0 columns.
    return matrix.size() == 0;
  }

  // Attempted initialization of a matrix with negative rows/columns.
  bool test2_matrixInit()
  {
    std::vector<std::vector<int>> matrix;
    NS_MATRIX::matrixInit(matrix, -1, -1);

    // If there are 0 rows, then there are automatically 0 columns.
    return matrix.size() == 0;
  }

  // Initialization of a 3 x 3 matrix.
  bool test3_matrixInit()
  {
    std::vector<std::vector<int>> matrix;
    NS_MATRIX::matrixInit(matrix, 3, 3);

    return (matrix.size() == 3 && matrix.at(2).size() == 3);
  }

  // Tokens of equal frequency.
  bool test1_operatorLE()
  {
    NS_TOKEN_FREQ::TokenFreq token1 = {"", 0};
    NS_TOKEN_FREQ::TokenFreq token2 = {"", 0};

    return token1 <= token2;
  }

  // Left token greater than right token.
  bool test2_operatorLE()
  {
    NS_TOKEN_FREQ::TokenFreq token1 = {"", 5};
    NS_TOKEN_FREQ::TokenFreq token2 = {"", 0};

    return !(token1 <= token2);
  }

  // Left token less than right token.
  bool test3_operatorLE()
  {
    NS_TOKEN_FREQ::TokenFreq token1 = {"", 0};
    NS_TOKEN_FREQ::TokenFreq token2 = {"", 5};

    return token1 <= token2;
  }

  bool test1_operatorPlus()
  {
    NS_TOKEN_FREQ::TokenFreq intended = {"Left or Right", 2};
    NS_TOKEN_FREQ::TokenFreq token1 = {"Left", 1};
    NS_TOKEN_FREQ::TokenFreq token2 = {"Right", 1};
    NS_TOKEN_FREQ::TokenFreq result = token1 + token2;

    return intended == result;
  }

  bool test2_operatorPlus()
  {
    NS_TOKEN_FREQ::TokenFreq intended = {"Left Right", 2};
    NS_TOKEN_FREQ::TokenFreq token1 = {"Left", 1};
    NS_TOKEN_FREQ::TokenFreq token2 = {"Right", 1};
    NS_TOKEN_FREQ::TokenFreq result = token1 + token2;

    return !(intended == result);
  }

  bool test3_operatorPlus()
  {
    NS_TOKEN_FREQ::TokenFreq intended = {"Left or Right", 2};
    NS_TOKEN_FREQ::TokenFreq token1 = {"Left", 1};
    NS_TOKEN_FREQ::TokenFreq token2 = {"Right", 0};
    NS_TOKEN_FREQ::TokenFreq result = token1 + token2;

    return !(intended == result);
  }

  bool test1_getTokeFreq()
  {
    std::vector<NS_TOKEN_FREQ::TokenFreq> test_vector;
    std::string input = "Hello brother I am John john I am very happy";

    NS_TOKEN_FREQ::getTokenFreqVec(input, test_vector);

    return !test_vector.empty();
  }

  bool test2_getTokeFreq()
  {
    std::vector<NS_TOKEN_FREQ::TokenFreq> test_vector;
    std::string input = " ";

    NS_TOKEN_FREQ::getTokenFreqVec(input, test_vector);

    return test_vector.empty();
  }

  bool test3_getTokeFreq()
  {
    std::vector<NS_TOKEN_FREQ::TokenFreq> test_vector;
    std::string input = "Hello World hello world bYe WoRlD";
    std::vector<NS_TOKEN_FREQ::TokenFreq> result_vector;
    // Initialization of result_vector.    
    NS_TOKEN_FREQ::TokenFreq temp{"bye", 1};
    result_vector.push_back(temp);
    temp = {"world", 3};
    result_vector.push_back(temp);
    temp = {"hello", 2};
    result_vector.push_back(temp);

    NS_TOKEN_FREQ::getTokenFreqVec(input, test_vector);

    bool result = true;
    for (int i = 0; i < result_vector.size(); i++)
    {
      if (result)
      {
        result = test_vector.at(i) == result_vector.at(i);
      }
    }

    return result;
  }
} // End NS_UNIT_TESTS