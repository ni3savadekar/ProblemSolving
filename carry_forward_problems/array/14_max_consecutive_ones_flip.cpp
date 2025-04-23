/*
14. Max Consecutive Ones (with at most one zero flipped)
Problem: Maximize consecutive 1s by flipping at most one 0.
Approach: Carry zero count in sliding window.
*/

#include <vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int left = 0, zeroCount = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); ++right) {
        if (nums[right] == 0) zeroCount++;
        while (zeroCount > 1) {
            if (nums[left++] == 0) zeroCount--;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}