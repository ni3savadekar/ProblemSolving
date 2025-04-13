#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int j = 0; // points to position of last unique element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int newLen = removeDuplicates(nums);
    cout << "Length after removing duplicates: " << newLen << endl;
    return 0;
}
