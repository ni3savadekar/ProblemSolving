/*
3. Prefix Sum Array
Problem: Find sum of elements between indices L and R.
Approach: Carry forward the sum.
*/
#include <vector>
using namespace std;
vector<int> buildPrefixSum(vector<int>& nums) {
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
        prefix[i] = prefix[i - 1] + nums[i];
    return prefix;
}