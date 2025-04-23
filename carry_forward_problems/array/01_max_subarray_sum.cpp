/*
1. Maximum Subarray Sum (Kadane’s Algorithm)
Problem: Find the contiguous subarray with the largest sum.
Approach: Carry forward the current sum and reset if it goes negative.
*/

#include <vector>
#include <algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}