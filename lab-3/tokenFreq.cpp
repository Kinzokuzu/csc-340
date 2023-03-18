#ifndef TOKENFREQ_CPP
#define TOKENFREQ_CPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

  void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec)
  {
    std::unordered_map<std::string, int> token_map;
    std::stringstream ss(istr);
    std::string token{""};

    while (ss >> token)
    {
      for (char& c : token)
      {
        c = std::tolower(c);
      }

      if (token_map.find(token) != token_map.end())
      {
        token_map[token]++;
      }
      else
      {
        token_map[token] = 1;
      }
    }

    TokenFreq tf;
    for (const auto& [key, value] : token_map)
    {
      tf.token = key;
      tf.freq = value;

      tfVec.push_back(tf);
    }
  }

  void selectionSort(std::vector<TokenFreq>& tokFreqVector)
  {
    if (tokFreqVector.size() <= 1) return;

    TokenFreq temp_tf;

    for (auto i : tokFreqVector)
    {
      for (auto j : tokFreqVector)
      {
        if (j <= i)
        {
          temp_tf = i;
          i = j;
          j = i;
        }
      }
    }
  }
  // Algorithm for insertionSort() was given by algolist.net 
  void insertionSort(std::vector<TokenFreq>& tokFreqVector)
  {
    if (tokFreqVector.size() <= 1) return;

    int i, j;
    NS_TOKEN_FREQ::TokenFreq temp;

    for (i = 1; i < tokFreqVector.size(); i++)
    {
      j = i;
      while (j > 0 && tokFreqVector.at(j - 1) <= tokFreqVector.at(j))
      {
        temp = tokFreqVector.at(j);
        tokFreqVector.at(j) = tokFreqVector.at(j - 1);
        tokFreqVector.at(j - 1);
        j--;
      }
    }
  }
} // End namespace NS_TOKEN_FREQ

#endif