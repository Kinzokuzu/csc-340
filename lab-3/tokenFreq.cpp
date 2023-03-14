#ifndef TOKENFREQ_CPP
#define TOKENFREQ_CPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

#include "tokenFreq.h"

namespace NS_TOKEN_FREQ
{
  struct TokenFreq
  {
    std::string token; // Holds the actual charater sequence of the token.
    int freq;
  };

  bool operator==(const struct TokenFreq& lhs, const struct TokenFreq& rhs)
  {
    bool result = lhs.token == rhs.token;

    if(result)
      result = lhs.freq == rhs.freq;

    return result;
  }

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
  // I don't like this implementation.  CHANGE IT!!!
  void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec)
  {
    std::unordered_map<std::string, int> token_map;
  
    std::string current_word{""};
    bool in_word{false};

    for (auto i : istr)
    {
      // Our tokens (words) will be bounded by a space character (' ').
      if (i == ' ')
      {
        in_word = false;
      }
      else
      {
        in_word = true;
      }

      if (in_word)
      {
        current_word.push_back(i); 
      }
      else
      {
        // Turn the current word into all lowercase characters
        for (char& c : current_word)
        {
          c = std::tolower(c);
        }

        if (token_map.contains(current_word))
          token_map.at(current_word)++;
        else
          token_map[current_word] = 1;
      }
    }
  }
  // TO-D0: Implement me!
  void selectionSort(std::vector<TokenFreq>& tokFreqVector);
  // TO-DO: Implement me!
  void insertionSort(std::vector<TokenFreq>& tokFreqVector);
} // End namespace NS_TOKEN_FREQ

#endif