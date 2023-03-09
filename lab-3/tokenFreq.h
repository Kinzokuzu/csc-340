#ifndef TOKENFREQ_H
#define TOKENFREQ_H

#include <string>

struct TokenFreq
{
  std::string token; // Holds the actual charater sequence of the token.
  int freq;
};

// Compares the frequency field of two TokenFreq objects. 
bool operator<=(const TokenFreq& lhs, const TokenFreq& rhs);

// Returns a TokenFreq object with the token field as "lhs.token or rhs.token"
// and the freq field as the sum of lhs.freq and rhs.freq.
TokenFreq operator+(const TokenFreq& lhs, const TokenFreq& rhs);

// TO-DO: Write my documentation.
std::ostream& operator<<(std::ostream& out, const TokenFreq token_obj);

#endif