/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> tar;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int t = nums[i];
      if (t + nums[i + 1] + nums[i + 2] > 0) {
        break;
      }
      if (t + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int small = i + 1;
      int big = nums.size() - 1;
      while (small < big) {
        int sum = nums[small] + nums[big] + t;
        if (sum < 0) {
          small++;
        } else if (sum == 0) {
          tar.push_back({nums[i], nums[small], nums[big]});
          while (small < big && nums[small] == nums[small + 1])
            small++;
          while (small < big && nums[big] == nums[big - 1])
            big--;
          small++;
          big--;
        } else {
          big--;
        }
      }
    }
    return tar;
  }

  // private:
  //   bool check(int i, int j, int k) {
  //     if (i == k || i == j || k == j) {
  //       return false;
  //     }
  //     return true;
  //   }
};
// @lc code=end
