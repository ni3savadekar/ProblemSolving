#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 0;

    // Trick: Fix the third side and search backward with two pointers
    for (int k = nums.size() - 1; k >= 2; --k) {
        int left = 0, right = k - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[k]) {
                count += right - left;
                right--;
            } else {
                left++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 2, 3, 4};
    cout << "Valid triangle count: " << triangleNumber(nums) << endl;
    return 0;
}
