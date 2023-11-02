//MST
//Prims Algorithm
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>g[1000];

int Minspan(int s,int n){
    using pii = pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});
    int vis[1000];
    //int vis[100] = {0};
    memset(vis,0,1000);
    int cost = 0;

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int wt = node.first;
        int u  = node.second;
        //cout<<u<<endl;
        if(vis[u]) continue;
        
        cost += wt;
        vis[u] = 1;
        //cout<<u<<"-> "<<wt<<endl;
        for(auto it : g[u]){
            if(vis[it.first]) continue;
            pq.push({it.second,it.first});
        }
    }
    return cost;

}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});

    }
    cout<<Minspan(1,n);
    return 0;
}