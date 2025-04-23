#include <vector>
#include <algorithm>
using namespace std;
int maximumScore(vector<int>& nums, int k) {
    int n = nums.size(), left = k, right = k, minVal = nums[k], score = nums[k];
    while (left > 0 || right < n - 1) {
        if (left == 0 || (right < n - 1 && nums[right + 1] >= nums[left - 1]))
            minVal = min(minVal, nums[++right]);
        else
            minVal = min(minVal, nums[--left]);
        score = max(score, minVal * (right - left + 1));
    }
    return score;
}