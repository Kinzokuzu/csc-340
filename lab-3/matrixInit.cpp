#include <vector>
#include "matrixInit.h"

namespace NS_MATRIX
{
  void matrixInit(std::vector<std::vector<int>>& matrix, int numRows,
                  int numCols)
  {
    matrix.resize(numRows, std::vector<int>(numCols));
  }
} // End namespace NS_MATRIX