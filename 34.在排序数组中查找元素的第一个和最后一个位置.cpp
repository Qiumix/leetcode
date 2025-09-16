/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }
    vector<int> ans;
    int l = 0, r = nums.size() - 1;
    int mid;
    while (l < r + 1) {
      mid = l + (r - l) / 2;
      if (nums[mid] > target) {
        l = mid + 1;
      } else if (nums[mid] < target) {
        r = mid - 1;
      }
    }
    if (l == r) {
      return {-1, -1};
    }
  }
};
// @lc code=end
