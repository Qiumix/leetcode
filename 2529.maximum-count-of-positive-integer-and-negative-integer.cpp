// @leet start
#include <vector>
using namespace std;
class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int left = lower_bound(nums, 0);
    int right = lower_bound(nums, 1) - 1;
    left = left, right = nums.size() - right - 1;
    return left > right ? left : right;
  }

private:
  int lower_bound(vector<int> &nums, int target) {
    int left = -1, right = nums.size(), mid;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return right;
  }
};
// @leet end
