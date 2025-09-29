// @leet start
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    vector<int> ans(spells.size());
    sort(potions.begin(), potions.end());
    int spell, start;
    long long miniPotion;
    for (int i = 0; i < spells.size(); i++) {
      miniPotion = (success + spells[i] - 1) / spells[i];
      int pos = lower_bound(potions.begin(), potions.end(), miniPotion) -
                potions.begin();
      ans[i] = potions.size() - pos;
    }
    return ans;
  }
};
// @leet end
