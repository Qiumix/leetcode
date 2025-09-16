/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;
    for (auto &str : strs) {
      auto key = str;
      sort(key.begin(), key.end());
      map[key].emplace_back(str);
    }
    vector<vector<string>> tar;
    for (auto it = map.begin(); it != map.end(); it++) {
      tar.emplace_back(it->second);
    }
    return tar;
  }
};
// @lc code=end
