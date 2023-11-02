//Coin change
#include<bits/stdc++.h>
using namespace std;
vector<int>coin;
int max_i[100][100];
const int inf=10000000;
int n,w;
int f(int i,int sum)
{

    if(sum==w) return 0;

    if(i==n) return inf;

    if(max_i[i][sum] != -1) return max_i[i][sum];

    int take = 1+ f(i+1,sum+coin[i]);
    int dont = f(i+1,sum);
    max_i[i][sum] = min(take,dont);
    
    return max_i[i][sum];
}
int main()
{
    int i,j,k;
    cin>>n>>w;
    memset(max_i,-1,sizeof(max_i));
    for(i=0;i<n;i++)
    {
        cin>>k;
        coin.push_back(k);
    }
    cout<<f(0,0)<<endl;
}
/*
5 22
2 5 9 13 15
*/
