/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int l = 0, r = 0;
    set<char> cur;
    char c;
    while (r < s.size()) {
      c = s[r];
      if (cur.find(c) == cur.end()) {
        cur.insert(c);
        ans = max(int(cur.size()), ans);
      } else {
        while (c != s[l]) {
          cur.erase(s[l++]);
        }
        l++;
      }
      r++;
    }
    return ans;
  }
};
// @lc code=end
