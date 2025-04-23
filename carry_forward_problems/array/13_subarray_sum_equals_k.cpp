/*
13. Subarray Sum Equals K (with negatives)
Problem: Count subarrays with exact sum K.
Approach: Carry prefix sum with hashmap for frequency.
*/

#include <vector>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount{{0, 1}};
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        count += prefixSumCount[sum - k];
        prefixSumCount[sum]++;
    }
    return count;
}