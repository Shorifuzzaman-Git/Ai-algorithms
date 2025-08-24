//complexity O(m^V)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c){
    for (int i = 0; i < graph[v].size(); i++){
        if (color[graph[v][i]] == c)
        return false;
    }
    return true;
}

bool graphColor(vector<vector<int>>& graph, int m, vector<int>& color, int v){
    if (v == graph.size())return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if(graphColor(graph, m, color, v + 1))return true;
            color[v] = 0;
        }
    }

    return false;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V+1);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int m;
    cin >> m;
    vector<int> color(V, 0);

    if(graphColor(graph, m, color, 0)) {
        for (int i = 0; i < V; i++){
            cout << "Vertex " << i << " ---> Color " << color[i] << "\n";
        }    
    } 
    else cout << "Solution does not exist\n";

}

// 4 5
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3
// 3