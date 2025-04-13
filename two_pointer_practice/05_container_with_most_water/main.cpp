#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(const vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxA = 0;

    // Trick: Move the pointer with the smaller height
    while (left < right) {
        int h = min(height[left], height[right]);
        maxA = max(maxA, h * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }

    return maxA;
}

int main() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << "Max water container area: " << maxArea(heights) << endl;
    return 0;
}
