#include <vector>
using namespace std;
int longestEvenOddSubarray(vector<int>& arr) {
    int maxLen = 1, currLen = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if ((arr[i] % 2) != (arr[i - 1] % 2))
            currLen++;
        else
            currLen = 1;
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}