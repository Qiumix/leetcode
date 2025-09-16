/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    rp = height.size() - 1;
    lp = 0;
    update(height);
    while (lp < rp) {
      if (height[lp] < height[rp]) {
        lp++;
        if (height[l] >= height[lp]) {
          continue;
        }
        if (judge(height)) {
          update(height);
        }
      } else {
        rp--;
        if (height[r] >= height[rp]) {
          continue;
        }
        if (judge(height)) {
          update(height);
        }
      }
    }
    return area;
  }

private:
  int width, area, r, l, rp, lp;
  void update(vector<int> &height) {
    r = rp, l = lp;
    width = r - l;
    area = min(height[r], height[l]) * width;
  }
  bool judge(vector<int> height) {
    int newW = rp - lp;
    int newA = newW * min(height[rp], height[lp]);
    if (newA > area) {
      return true;
    }
    return false;
  }
};
// @lc code=end
