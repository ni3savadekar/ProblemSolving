#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;

    // Trick: Sliding window with character set to maintain uniqueness
    for (int right = 0; right < s.size(); ++right) {
        while (seen.count(s[right])) {
            seen.erase(s[left++]);
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest unique substring: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
