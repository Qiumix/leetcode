/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) {
      return 0;
    }
    int ans = 0;
    int mul = 1;
    int l = 0, r = 0;
    while (r < nums.size()) {
      mul *= nums[r];
      while (mul > k - 1) {
        mul /= nums[l++];
      }
      ans += 1 + r - l;
      r++;
    }
    return ans;
  }
};
// @lc code=end
