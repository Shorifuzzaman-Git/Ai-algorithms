#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> g;
unordered_map<char, bool> vis;
unordered_map<char, char> parent;
bool found = false;

void DLS(char curr, char end, int limit, int depth) {
    if (depth > limit || found) return;

    vis[curr] = true;

    if (curr == end) {
        found = true;
        return;
    }

    for (char neighbor : g[curr]) {
        if (!vis[neighbor]) {
            parent[neighbor] = curr;
            DLS(neighbor, end, limit, depth + 1);
        }
    }
}

void printPath(char start, char end) {
    if (!found) {
        cout << "No path found from " << start << " to " << end << " within depth limit.\n";
        return;
    }

    vector<char> path;
    for (char at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "DLS path from " << start << " to " << end << ": ";
    for (char node : path) cout << node << ' ';
    cout << '\n';
}

int main() {
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter each edge (e.g., A B):\n";

    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    char start, end;
    int limit;
    cout << "Enter start and end node:\n";
    cin >> start >> end;
    cout << "Enter depth limit: ";
    cin >> limit;

    vis.clear();
    parent.clear();
    found = false;

    DLS(start, end, limit, 0);
    printPath(start, end);

    return 0;
}
