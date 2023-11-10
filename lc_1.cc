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