#include <string>
using namespace std;
int minSwaps(string s) {
    int balance = 0, maxImbalance = 0;
    for (char c : s) {
        if (c == '[') balance++;
        else balance--;
        if (balance < 0) maxImbalance = max(maxImbalance, -balance);
    }
    return (maxImbalance + 1) / 2;
}