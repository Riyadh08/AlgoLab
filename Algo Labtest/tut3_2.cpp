//Floyd Warshall algorithm
//Undirect Graph
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+12;


int main() {
   int n,m;
   cin>>n>>m;

    int arr[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = arr[j][i] = INF;
        }
    }
    //cout<<arr[1][1]<<endl;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u][v] = arr[v][u] = min(arr[u][v],wt);
    }


   for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }

  //cout<<arr[1][1]<<" "<<arr[1][3]<<endl;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

    return 0;
}
