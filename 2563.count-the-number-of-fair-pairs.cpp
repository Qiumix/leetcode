// @leet start
#include <vector>
using namespace std;
class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    long long ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      auto start = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
      auto end = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
      ans -= end - start;
    }
    return ans;
  }
};
// @leet end
