#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<int>G[N];
vector<int>par(N,-1),vis(N,0);

vector<int> BFS(int src,int goal){
    queue<int>q;

    par[src]=-1;
    q.push(src);

    while (!q.empty()){
        int node=q.front();
        q.pop();

        if(node==goal)break;
        vis[src]=1;

        for(auto child:G[node]){
            if(vis[child]==0){
                q.push(child);
                vis[child]=1;
                par[child]=node;
            }
        }
    }
    
    if(vis[goal]==0){
        return {};
    }
    else{
        vector<int>path;
        for(int i=goal;i>0;i=par[i]){
            path.push_back(i);
        }
        reverse(path.begin(),path.end());
        return path;
    }

}

int main(){
    int n,m;
    cin>>n>>m;

    while (m--){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int src,goal;
    cin>>src>>goal;
    vector<int>path=BFS(src,goal);
    if(path.empty())cout<<"No path found\n";
    else{
        for(auto i:path)cout<<i<<' ';
    }
    
}

/*
5 4
1 2
1 3
2 4
2 5
*/