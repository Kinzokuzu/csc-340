#ifndef MATRIXINIT_H
#define MATRIXINIT_H

#include <vector>

namespace NS_MATRIX
{
  // Creates a matrix of dimensionality numRows x numCols, where matrix
  // matrix starts with an initial size of 0.
  void matrixInit(std::vector<std::vector<int>>& matrix, int numRows,
                  int numCols);
} // End namespace NS_MATRIX

#endif