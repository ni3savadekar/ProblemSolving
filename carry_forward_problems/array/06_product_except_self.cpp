/*
6. Product of Array Except Self
Problem: Return array where each element is the product of all elements except itself.
Approach: Prefix product (carry forward), then postfix pass.
*/

#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    return result;
}