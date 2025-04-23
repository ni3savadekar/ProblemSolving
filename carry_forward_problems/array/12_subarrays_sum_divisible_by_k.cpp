/*
12. Subarrays with Sum Divisible by K
Problem: Count subarrays where the sum is divisible by K.
Approach: Carry prefix sums and use mod + hashmap.
*/

#include <vector>
#include <unordered_map>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> modCount{{0, 1}};
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        int mod = ((sum % k) + k) % k;
        count += modCount[mod];
        modCount[mod]++;
    }
    return count;
}