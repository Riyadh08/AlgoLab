//Bellman ford algo
#include<bits/stdc++.h>
using namespace std;

vector<int>bellman_ford(int n,vector<vector<int>>&edges,int s){

    vector<int>dist(n,1e8);
    dist[s] = 0;

    for(int i=0;i<n-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
     
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vector<int>temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        edges.push_back(temp);
        temp.clear();

    }
    int s;
    cin>>s;

    vector<int>demo;
    demo.push_back(-1);

    // cout<<" hi"<<endl;
    vector<int> dist = bellman_ford(n,edges,s);

    if(dist == demo){ 
    cout<<"Negative cycle is present"<<endl;
    return 0;
    }

    // for(int tt : dist) cout<<tt<<" ";
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}