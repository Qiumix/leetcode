// @leet start
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int right = lower_bound(nums, target);
    if (right == nums.size() || nums[right] != target) {
      return {-1, -1};
    }
    int left = lower_bound(nums, target + 1) - 1;
    return {right, left};
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
