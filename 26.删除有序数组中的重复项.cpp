/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    int fast = 1, slow = 1;
    while (fast < size) {
      if (nums[fast] != nums[fast - 1]) {
        nums[slow++] = nums[fast];
      }
      fast++;
    }
    return slow;
  }

private:
};
// @lc code=end
// int main() {
//     vector<int> testcase = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//     vector<int> expect = { 0, 1, 2, 3, 4 };
//     Solution test;
//     int k = test.removeDuplicates(testcase);
//     if (k != expect.size()) {
//         cout << "size error" << endl;
//     }
//     for (int i = 0; i < k; i++) {
//         if (testcase[i] != expect[i]) {
//             cout << testcase[i] << " : " << expect[i] << endl;
//         }
//     }
//     return 0;
// }