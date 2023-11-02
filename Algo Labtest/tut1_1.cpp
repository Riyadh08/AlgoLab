//Dijkstra Algo

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+12;

vector <int> dijkstra(int n, vector<pair<int,int>> g[], int s)
    {
        // Code here
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>dist(n+1,INF);
        
        //for(int i=0;i<=n;i++) dist[i] = 1e9;
        dist[s] = 0;
        pq.push({0,s});
       
        
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            //cout<<dis<<" "<<node<<" "<<dist[node]<<endl;
            if ( d > dist[u]) continue;
            
            for(auto it: g[u]){
                int wt = it.second;
                int v = it.first;
                //Relaxition
                if(d + wt < dist[v]){

                    dist[v] = d + wt;
                    pq.push({dist[v],v});
                   
                }
            }
        }
        return dist;
    }



int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int source = 1;
   // cin>>source;
    vector<int>dist = dijkstra(n,g,source);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}