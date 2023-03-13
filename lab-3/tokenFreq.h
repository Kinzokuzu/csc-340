#ifndef TOKENFREQ_H
#define TOKENFREQ_H

#include <iostream>
#include <string>

#include "tokenFreq.cpp"

namespace NS_TOKEN_FREQ
{
  struct TokenFreq;

  // Compares the frequency field of two TokenFreq objects. 
  bool operator<=(const struct TokenFreq& lhs, const struct TokenFreq& rhs);

  // Returns a TokenFreq object with the token field as "lhs.token or 
  // rhs.token" and the freq field as the sum of lhs.freq and rhs.freq.
  TokenFreq operator+(const struct TokenFreq& lhs, const struct TokenFreq& rhs);

  // Writes "(token, freq) = ([token], [frequency])" to a character based
  // out-stream.
  std::ostream& operator<<(std::ostream& out, const TokenFreq obj);

  // Creates of list of unique and case insensitive tokens, and their
  // correspoinding frequencies, identified withing the string istr, and
  // stores them in vector tfVec.
  //void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);

  // This function receives a vector of TokenFreq objects by reference and
  // applies the selection sort algorithm to sort this vector in increasing
  // order of token frequencies.
  //void selectionSort(std::vector<TokenFreq>& tokFreqVector);

  // This function receives a vector of TokenFreq objects by reference and
  // applies the insertion sort algorithm to sort this vector in descending
  // order of token frequencies.
  //void insertionSort(std::vector<TokenFreq>& tokFreqVector);
} // End namespace NS_TOKEN_FREQ

#endif