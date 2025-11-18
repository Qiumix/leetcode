#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int sum = 0;
    stack<pair<int, int>> stk;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          sum++;
          stk.push({i, j});
          while (!stk.empty()) {
            auto tp = stk.top();
            stk.pop();
            int k = tp.first, d = tp.second;
            if (tp.first < 0 || tp.second < 0 || //
                tp.first >= grid.size() ||       //
                tp.second >= grid[0].size() ||   //
                grid[k][d] == '0' || grid[k][d] == '2') {
              continue;
            } else if (grid[tp.first][tp.second] == '1') {
              grid[tp.first][tp.second] = '2';
              stk.push({k - 1, d});
              stk.push({k + 1, d});
              stk.push({k, d - 1});
              stk.push({k, d + 1});
            }
          }
        }
      }
    }
    return sum;
  }
};
// @lc code=end

int main() {
  Solution solution;
  vector<vector<char>> v(2);
  v[0] = {'1'};
  v[1] = {'1'};
  cout << solution.numIslands(v) << endl;
}