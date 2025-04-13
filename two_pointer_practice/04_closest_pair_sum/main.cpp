#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int closestPairSum(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int closest = nums[left] + nums[right];

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (abs(target - sum) < abs(target - closest)) {
            closest = sum;
        }
        if (sum < target) left++;
        else right--;
    }

    return closest;
}

int main() {
    vector<int> nums = {1, 3, 4, 7, 10};
    int target = 15;
    cout << "Closest sum: " << closestPairSum(nums, target) << endl;
    return 0;
}
