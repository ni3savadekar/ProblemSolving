#include <vector>
using namespace std;
bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = recStack[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && dfs(neighbor, graph, visited, recStack)) return true;
        if (recStack[neighbor]) return true;
    }
    recStack[node] = false;
    return false;
}
bool hasCycle(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false), recStack(n, false);
    for (int i = 0; i < n; ++i)
        if (!visited[i] && dfs(i, graph, visited, recStack))
            return true;
    return false;
}