// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>

class TwoSum {
public:
  std::vector<int> twoSum_ver01(std::vector<int> &nums, int target) {
    std::vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (target == (nums[i] + nums[j])) {
          result.push_back(i);
          result.push_back(j);
        }
      }
    }
    return result;
  }

  // Fix one the numbers x, scan the entire array to find number y which is
  // (target - x)
  std::vector<int> twoSum_ver02(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> seen;

    int complement = 0;
    for (int i = 0; i < nums.size(); ++i) {
      complement = target - nums[i];

      // 1. Check if the complement already exists in our map
      if (seen.find(complement) != seen.end()) {
        /* begin is first room of hallway, and end() is exit door of hallway
         * .contains() c++20 */

        return {seen[complement], i};
      }
      // 2. Add current number and its index *after* searching
      seen[nums[i]] =
          i; // add index of value in vector with index save it to map
    }

    return {}; // Return empty vector if no pair is found
  }
};