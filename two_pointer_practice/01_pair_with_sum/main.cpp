#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool hasPairWithSum(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

int countPairsWithSum(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, count = 0;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            count++;
            int l_val = nums[left], r_val = nums[right];
            while (left < right && nums[left] == l_val) left++;
            while (left < right && nums[right] == r_val) right--;
        } else if (sum < target) left++;
        else right--;
    }
    return count;
}

vector<pair<int, int>> getAllPairsWithSum(const vector<int>& nums, int target) {
    vector<pair<int, int>> result;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.emplace_back(nums[left], nums[right]);
            int l_val = nums[left], r_val = nums[right];
            while (left < right && nums[left] == l_val) left++;
            while (left < right && nums[right] == r_val) right--;
        } else if (sum < target) left++;
        else right--;
    }
    return result;
}

pair<int, int> getIndicesOfPairWithSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> sortedNums = {1, 2, 2, 3, 4, 4, 5, 6};
    int target = 7;
    cout << "Has Pair: " << (hasPairWithSum(sortedNums, target) ? "Yes" : "No") << endl;
    cout << "Count: " << countPairsWithSum(sortedNums, target) << endl;
    auto pairs = getAllPairsWithSum(sortedNums, target);
    for (auto& [a, b] : pairs) cout << a << " + " << b << endl;
    vector<int> unsorted = {5, 2, 7, 1, 3};
    auto [i, j] = getIndicesOfPairWithSum(unsorted, target);
    cout << "Indices: " << i << ", " << j << endl;
    return 0;
}
