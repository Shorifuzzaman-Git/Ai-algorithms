#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<pair<int,int>>G[N];
vector<int>dis(N,INT_MAX),par(N,-1),vis(N,0),heuristics(N,0);
int n,m;

vector<int> Dijkstra(int src,int goal){
    set<pair<int,int>>s;
    dis[src]=0;
    par[src]=-1;
    s.insert({heuristics[src],src});

    while (!s.empty()){
        auto it=*s.begin();
        s.erase(it);
        int node=it.second;
        
        if(node==goal)break;;
        if(vis[node]==1)continue;
        vis[node]=1;

        for(auto child:G[node]){
            if(dis[child.first]>child.second+dis[node]){
                dis[child.first]=child.second+dis[node];
                s.insert({dis[child.first]+heuristics[child.first],child.first});
                par[child.first]=node;
            }
        }
    }

    if(dis[goal]==INT_MAX)return {};
    vector<int>path;
    for(int i=goal;i!=-1;i=par[i]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    return path;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>heuristics[i];
    }
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    int src,goal;
    cin>>src>>goal;

    vector<int>path=Dijkstra(src,goal);
    if(!path.empty()){
        for(auto i:path){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    else cout<<"No path found"<<endl;
}

/*
5 6
7 6 2 1 0
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
0 4
*/
