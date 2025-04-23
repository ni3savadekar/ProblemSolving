/*
9. Running Sum of 1D Array
Problem: Return running sum of the array.
Approach: Straightforward carry forward of sum.
*/
#include <vector>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];
    return nums;
}