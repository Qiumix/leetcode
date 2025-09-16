/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int len = nums.size() + 1;
    int sum = 0;
    int l = 0, r = 0;
    while (r < nums.size()) {
      sum += nums[r];
      while (sum > target - 1) {
        len = min(len, r - l + 1);
        sum -= nums[l++];
      }
      r++;
    }
    if (len == nums.size() + 1) {
      return 0;
    }
    return len;
  }
};
// @lc code=end
