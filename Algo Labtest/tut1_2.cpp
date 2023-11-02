//Dijkstra
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+12;
int parent[100000];
vector<int> path;

vector<int> dijkstra(int n, vector<pair<int, int>> g[], int s) {
    // Rest of your dijkstra code remains the same
    using pii = pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(n+1,INF);

    dist[s] = 0;
    pq.push({0,s});
    parent[s] = -1;

    while(!pq.empty()){
        
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d>dist[u]) continue;

        for(auto it : g[u]){
            int wt = it.second;
            int v = it.first;

            if(d + wt < dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
                parent[v] = u;
            }
        }
    }

    return dist;
}

void findPath(int node) {
    if (node == -1) return;
    findPath(parent[node]);
    path.push_back(node);
}

int main() {
    // Your main function remains the same
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int s;
    cin >> s;
    vector<int> dist = dijkstra(n, g, s);

    findPath(n);
    for (int node : path) {
        cout << node << " ";
    }

    return 0;
}
