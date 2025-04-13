#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Trick: Nested 2Sum inside two for-loops, with duplicate skips
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = nums.size() - 1;
            long long t = target - (long long)nums[i] - nums[j];
            while (left < right) {
                long long sum = nums[left] + nums[right];
                if (sum == t) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    int lv = nums[left], rv = nums[right];
                    while (left < right && nums[left] == lv) left++;
                    while (left < right && nums[right] == rv) right--;
                } else if (sum < t) left++;
                else right--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto result = fourSum(nums, target);
    for (auto& quad : result) {
        for (int n : quad) cout << n << " ";
        cout << endl;
    }
    return 0;
}
