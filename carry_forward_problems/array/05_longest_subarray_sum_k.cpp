/*
Longest Subarray with Given Sum (Positive numbers)
Problem: Find length of longest subarray with given sum K.
Approach: Carry forward sliding window sum.
*/

#include <vector>
#include <algorithm>
using namespace std;
int longestSubarrayWithSumK(vector<int>& nums, int k) {
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];
        while (sum > k)
            sum -= nums[left++];
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}