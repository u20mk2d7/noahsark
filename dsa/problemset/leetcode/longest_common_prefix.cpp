// https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix_ver01(std::vector<std::string> &strs) {
    if (strs.size() == 0)
      return "";

    std::string temp = "";
    for (int i = 0; i < strs[0].size(); ++i) {
      temp.push_back(strs[0][i]);
      for (int j = 1; j < strs.size(); ++j) {
        // check strs[j].size() < strs[i].size() or not ?
        if (i >= strs[j].size() || strs[j][i] != temp[i]) {
          temp.pop_back();
          return temp;
        }
      }
    }
    return temp;
  }
};
