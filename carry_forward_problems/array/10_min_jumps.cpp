/*
10. Minimum Jumps to Reach End (Greedy Carry)
Problem: Minimum number of jumps to reach end.
Approach: Carry forward max reach.
*/

#include <vector>
#include <algorithm>
using namespace std;
int jump(vector<int>& nums) {
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}