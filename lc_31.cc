// https://leetcode.com/problems/next-permutation/

/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

#include <vector>

#include "lc_vec_helper.h"

using namespace std;

/*
1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
2. Find the largest index l > k such that nums[k] < nums[l].
3. Swap nums[k] and nums[l].
4. Reverse the sub-array nums[k + 1:].
*/
void nextPermutation(std::vector<int>& nums) {
  int n = nums.size();
  int k, l;
  for (k=n-2; k>=0; k--) {
    if (nums[k] < nums[k+1])
      break;
  }
  if (k < 0) {
    reverse(nums.begin(), nums.end());
  } else {
    for (l=n-1; l>k; l--) {
      if (nums[l] > nums[k])
        break;
    }
    std::swap(nums[l], nums[k]);
    std::reverse(nums.begin()+k+1, nums.end());
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v1 = {1, 2, 3};
  nextPermutation(v1);
  printVectorInline<int>(v1);

  std::vector<int> v2 = {3, 2, 1};
  nextPermutation(v2);
  printVectorInline<int>(v2);

  std::vector<int> v3 = {1, 1, 5};
  nextPermutation(v3);
  printVectorInline<int>(v3);

  return 0;
}