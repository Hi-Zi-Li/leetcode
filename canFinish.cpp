#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool dfs (vector<vector<int>> &adjList, vector<int> &starts, vector<int> &indegrees, vector<int> &visited, int course) {
    while (!starts.empty()) {
        int curr = starts.back();
        starts.pop_back();
        visited[curr] = 1;
        for (auto &next: adjList[curr]) {
            indegrees[next]--;
            if (indegrees[next] == -1)
                return false;
            if (indegrees[next] == 0 && visited[next] == 0)
                starts.push_back(next);
        }
    }
    for (auto &i: indegrees)
        if (i != 0)
            return false;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (auto &edge: prerequisites) {
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int> indegree(numCourses, 0);
    for (auto &edge: prerequisites) {
        indegree[edge[0]]++;
    }
    vector<int> starts;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            starts.push_back(i);
        }
    }
    if (starts.empty())
        return false;
    vector<int> visited(numCourses, 0);
    return dfs(adjList, starts, indegree, visited, numCourses);
}

int main() {
    // Test cases
    vector<vector<int>> prerequisites1 = {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    cout << canFinish(20, prerequisites1) << endl; // true
    vector<vector<int>> prerequisites2 = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
    cout << canFinish(7, prerequisites2) << endl; // false
    // vector<vector<int>> prerequisites3 = {{1,0},{2,0},{3,1},{3,4},{4,2},{2,3}};
    // cout << canFinish(6, prerequisites3) << endl; // true
    return 0;
}