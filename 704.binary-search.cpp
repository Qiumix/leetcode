// @leet start
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int p = (left + right) / 2;
    while (left < right) {
      if (nums[p] < target) {
        left = p;
      } else if (nums[p] > target) {
        right = p;
      } else {
        break;
      }
      p = (left + right) / 2;
    }
    if (left <= right) {
      return p;
    }
    return -1;
  }
};
int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
}
// @leet end
