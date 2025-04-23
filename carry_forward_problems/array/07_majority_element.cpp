/*
7. Majority Element (Boyer-Moore Voting)
Problem: Find element appearing more than n/2 times.
Approach: Carry a count with cancellation.
*/

#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}