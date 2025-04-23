/*
16. Largest Subarray with Equal 0s and 1s
Problem: Convert 0 to -1, and find max subarray with sum 0.
Approach: Carry prefix sum with hashmap.
*/

#include <vector>
#include <unordered_map>
using namespace std;
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp{{0, -1}};
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i] == 0 ? -1 : 1;
        if (mp.count(sum))
            maxLen = max(maxLen, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return maxLen;
}