#include <vector>
using namespace std;
vector<int> buildPrefixSum(vector<int>& nums) {
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
        prefix[i] = prefix[i - 1] + nums[i];
    return prefix;
}