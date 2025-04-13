#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Trick: Avoid duplicates by skipping repeated elements during iteration
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate 'i'
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                res.push_back({nums[i], nums[left], nums[right]});
                int leftVal = nums[left], rightVal = nums[right];
                while (left < right && nums[left] == leftVal) left++;   // skip duplicates
                while (left < right && nums[right] == rightVal) right--; // skip duplicates
            } else if (sum < target) left++;
            else right--;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto result = threeSum(nums);
    for (auto& triplet : result) {
        for (int num : triplet) cout << num << " ";
        cout << endl;
    }
    return 0;
}
