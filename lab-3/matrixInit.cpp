#ifndef MATRIXINIT_CPP
#define MATRIXINIT_CPP

#include <vector>
#include "matrixInit.h"

namespace NS_MATRIX
{
  void matrixInit(std::vector<std::vector<int>>& matrix, int numRows,
                  int numCols)
  {
    // Create 0 x 0 matrix given negative values
    if (numRows < 0 || numCols < 0)
    {
      matrix.resize(0, std::vector<int>(0));
    }
    else
    {
      matrix.resize(numRows, std::vector<int>(numCols));
    }
  }
} // End namespace NS_MATRIX

#endif