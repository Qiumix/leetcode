/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int trap(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int lm = 0, rm = 0;
    int ans = 0;
    while (l <= r) {
      lm = max(lm, height[l]);
      rm = max(rm, height[r]);
      if (lm < rm) {
        ans += lm - height[l++];
      } else {
        ans += rm - height[r--];
      }
    }
    return ans;
  }
};
// @lc code=end
