/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> t(2);
    int small = 0, big = numbers.size() - 1;
    while (1) {
      int temp = numbers[small] + numbers[big];
      if (temp > target) {
        big--;
      } else if (temp < target) {
        small++;
      } else {
        break;
      }
    }
    t[0] = small + 1;
    t[1] = big + 1;
    return t;
  }
};
// @lc code=end
