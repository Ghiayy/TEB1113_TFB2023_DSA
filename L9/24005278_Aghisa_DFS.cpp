#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, vector<char>> graph;
map<char, bool> visited;

void dfs(char node) {
    visited[node] = true;
    cout << node << " ";

    for (char neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    graph['A'] = {'B', 'D', 'C'};
    graph['B'] = {'A', 'E', 'D'};
    graph['C'] = {'A', 'D'};
    graph['D'] = {'A', 'C', 'E', 'B'};
    graph['E'] = {'B', 'D'};

    cout << "DFS starting from A:\n";
    dfs('A');

    return 0;
}

