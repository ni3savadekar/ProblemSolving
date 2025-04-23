/*

8. Balanced Parentheses
Problem: Check if string has balanced parentheses.
Approach: Carry forward a counter.

*/

#include <string>
using namespace std;
bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') {
            if (--count < 0) return false;
        }
    }
    return count == 0;
}