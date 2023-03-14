/* Project Description
 * • Set up a 2D array with proper initial values using a vector of
 *   vectors.
 * • Given a string, implement a tokenizer to identify all the unique
 *   tokens contained whithin this string and the number of times (i.e.
 *   frequency) a given token appears in this string.
 * • Create a new datatype using struct to hold a token and its frequency;
 *   then overload a few operators for this new data type; finally, store
 *   and manage the objects of this new datatype by a vector.
 * • Implement the insertion sort algorithm to sort the list of tokens in
 *   increasing order of frequency.
 * • Implement the selection sort algorithm to sort the list of tokens in
 *   decreasing order of frequency.
 */
/* Algorithm Design
 * 
 * bool operator==(const struct TokenFreq& lhs, const struct TokenFreq& rhs);
 * Step 1: Compare the token field from both lhs and rhs, if equal continue,
 *         else return false.
 * Step 2: Compate the frequency field from both lhs and rhs, if equal return
 *         true, else return false.
 * 
 * bool operator<=(const struct TokenFreq& lhs, const struct TokenFreq& rhs);
 * Step 1: Return whether the frequency field of lhs is <= to the frequency
 *         field from rhs.
 * 
 * TokenFreq operator+(const struct TokenFreq& lhs, const struct TokenFreq& rhs);
 * Step 1: Return the concatnation of the token field of lhs and rhs and the
 *         addition of the frequency field of lhs and rhs.
 * 
 * std::ostream& operator<<(std::ostream& out, const TokenFreq obj);
 * Step 1: Pass "(token, freq) = ([token field of object], [frequency
 *         field of object])" to the out-stream object out.
 * 
 * std::string getToken(const std::string& input);
 * While there are still characters in input:
 *   While the current character is not a space:
 *     Add the current charater to the end of the current word.
 *   R
 * 
 * void getTokenFreqVec(std::string& istr, std::vector<TokenFreq>& tfVec);
 * Step 1: While there are words in istr, check whether this word (case
 *         insensitive) has been encountered previously:
 *         1a) If it has, add 1 to the frequency of times this word has been
 *             encountered, move on to the next word.
 *         1b) If it hasn't, add this word to a list of words (tokens) and
 *             increases it ecounter frequency by 1.
 * Note: Words (tokens) and their frequency's are to be stored in the function
 *       parameter tfVec.
 */
/* Test Cases
 *
 */
