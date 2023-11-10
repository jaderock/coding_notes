// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

size_t lengthOfLongestSubstring(string s) {
  size_t longest = 0;
  unordered_map<char, size_t> charToIdx;
  for (size_t i=0; i<s.length(); ++i) {
    char c = s[i];
    if (charToIdx.find(c) != charToIdx.end()) {
      size_t l = i - charToIdx[c];
      longest = std::max(longest, l);
    }
    charToIdx[c] = i;
  }
  return longest;
}

int main(int argc, char* argv[]) {
  size_t l0 = lengthOfLongestSubstring("abcabcbb");
  std::cout << l0 << std::endl;
  size_t l1 = lengthOfLongestSubstring("bbbbb");
  std::cout << l1 << std::endl;
  size_t l2 = lengthOfLongestSubstring("pwwkew");
  std::cout << l2 << std::endl;
  return 0;
}