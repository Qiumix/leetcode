#include <stack>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> ans(temperatures.size());
    stack<int> stk;
    for (int i = temperatures.size() - 1; i > -1; i--) {
      while (!stk.empty() && temperatures[stk.top()] <= temperatures[i])
        stk.pop();
      if (!stk.empty())
        ans[i] = stk.top() - i;
      stk.push(i);
    }
    return ans;
  }
};
// @lc code=end

int main() {
  Solution so;
  vector<int> v({73, 74, 75, 71, 69, 72, 76, 73});
  so.dailyTemperatures(v);
}