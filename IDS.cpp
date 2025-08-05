#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> g;
unordered_map<char, char> parent;
bool found = false;

bool DLS(char curr, char end, int limit, unordered_map<char, bool>& vis) {
    if (curr == end) {
        found = true;
        return true;
    }

    if (limit == 0) return false;

    vis[curr] = true;

    for (char neighbor : g[curr]) {
        if (!vis[neighbor]) {
            parent[neighbor] = curr;
            if (DLS(neighbor, end, limit - 1, vis)) return true;
        }
    }

    return false;
}

bool IDS(char start, char end, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; depth++) {
        unordered_map<char, bool> vis;
        parent.clear();
        found = false;

        //cout << "Trying depth limit: " << depth << '\n';
        if (DLS(start, end, depth, vis)) {
            return true;
        }
    }
    return false;
}

void printPath(char start, char end) {
    vector<char> path;
    for (char at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "IDS path from " << start << " to " << end << ": ";
    for (char node : path) cout << node << ' ';
    cout << '\n';
}

int main() {
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter each edge :\n";

    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    char start, end;
    int maxDepth;
    cout << "Enter start and end node:\n";
    cin >> start >> end;
    cout << "Enter max depth limit: ";
    cin >> maxDepth;

    if (IDS(start, end, maxDepth)) {
        printPath(start, end);
    } else {
        cout << "No path found from " << start << " to " << end << " within depth limit.\n";
    }

    return 0;
}
