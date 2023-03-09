#include <vector>
#include "matrixInit.h"

void matrixInit(std::vector<std::vector<int>>& matrix, int numRows,
                int numCols)
{
  matrix.resize(numRows, std::vector<int>(numCols));
}