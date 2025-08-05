#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<int>G[N];
vector<int>vis(N,0),par(N,-1);
vector<int>path;
bool found=false;

void DFS(int src,int goal){
    if(found)return;
    vis[src]=1;
    path.push_back(src);

    if(src==goal){
        found=true;
        return;
    }

    for(auto child:G[src]){
        if(vis[child]==0){
            DFS(child,goal);
            if(found)return;
        }
    }

    path.pop_back();
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int src,goal;
    cin>>src>>goal;
    DFS(src,goal);
    if(found){
        for(auto i:path)cout<<i<<' ';
    }
    else{
        cout<<"No path found\n";
    }
    

}

/*
5 4
1 2
1 3
2 4
2 5
*/