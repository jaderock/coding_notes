// https://leetcode.com/problems/two-sum/description/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <vector>
#include <unordered_map>

#include "lc_helper_func.h"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> r;
  unordered_map<int, int> numMap;
  for (size_t i=0; i<nums.size(); ++i) {
    int toFindNum = target - nums[i];
    if (numMap.find(toFindNum) != numMap.end()) {
      r.push_back(numMap[toFindNum]);
      r.push_back(i);
    } else {
      numMap[nums[i]] = i;
    }
  }
  return r;
}

int main(int argc, char* argv[]) {
  vector<int> v1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> r1 = twoSum(v1, target1);
  printVectorInline<int>(r1);

  vector<int> v2 = {3, 2, 4};
  int t2 = 6;
  vector<int> r2 = twoSum(v2, t2);
  printVectorInline<int>(r2);

  vector<int> v3 = {3, 3};
  int t3 = 6;
  vector<int> r3 = twoSum(v3, t3);
  printVectorInline<int>(r3);
}