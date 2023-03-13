#ifndef TOKENFREQ_CPP
#define TOKENFREQ_CPP

#include <algorithm>
#include <iostream>
#include <string>
#include "tokenFreq.h"

namespace NS_TOKEN_FREQ
{
  struct TokenFreq
  {
    std::string token; // Holds the actual charater sequence of the token.
    int freq;
  };

  bool operator<=(const struct TokenFreq& lhs, const struct TokenFreq& rhs)
  {
    return lhs.freq <= rhs.freq;
  }

  TokenFreq operator+(const struct TokenFreq& lhs, const struct TokenFreq& rhs)
  {
    return {lhs.token + " or " + rhs.token, lhs.freq + rhs.freq};
  }

  std::ostream& operator<<(std::ostream& out, const TokenFreq obj)
  {
    out << "(token, freq) = (" << obj.token << ", " << obj.freq << ")";
    return out;
  }
  // TO-DO: Implement me!
  //void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);
  // TO-D0: Implement me!
  //void selectionSort(std::vector<TokenFreq>& tokFreqVector);
  // TO-DO: Implement me!
  //void insertionSort(std::vector<TokenFreq>& tokFreqVector);
} // End namespace NS_TOKEN_FREQ

#endif