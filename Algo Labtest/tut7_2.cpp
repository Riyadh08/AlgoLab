// 0/1 knapsack 3D
#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> memo;
vector<int>weight;
vector<int>value;
vector<int>volume;

int knapsack( int n, int maxWeight, int maxVolume, int i) {
    // Base case: If we have considered all items or reached the capacity limit, return 0.
    if (i == 0 || maxWeight == 0 || maxVolume == 0) {
        return 0;
    }

    // Check if the result for this subproblem is already memoized
    if (memo[i][maxWeight][maxVolume] != -1) {
        return memo[i][maxWeight][maxVolume];
    }

    // If the current item's weight and volume exceed the available capacity, skip it.
    if (weight[i - 1] > maxWeight || volume[i - 1] > maxVolume) {
        int result = knapsack(n, maxWeight, maxVolume, i - 1);
        memo[i][maxWeight][maxVolume] = result;
        return result;
    }

    // Calculate the value if we include the current item and if we exclude it.
    int include = value[i - 1] + knapsack( n, maxWeight - weight[i - 1], maxVolume - volume[i - 1], i - 1);
    int exclude = knapsack( n, maxWeight, maxVolume, i - 1);

    // Compute and memoize the maximum value between including and excluding the current item.
    int result = max(include, exclude);
    return memo[i][maxWeight][maxVolume] = result;

    //return result;
}

int main() {
    int n;
    int maxWeight;
    int maxVolume;
    cin >> n >> maxWeight >> maxVolume;

   for (int i = 0; i < n; i++) {
        // cin >> weight[i];
        int x;
        cin>>x;
        weight.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        // cin >> volume[i];
        int x;
        cin>>x;
        volume.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        // cin >> value[i];
        int x;
        cin>>x;
        value.push_back(x);
    }

    // Initialize memoization vector with -1 values
    memo.resize(n + 1, vector<vector<int>>(maxWeight + 1, vector<int>(maxVolume + 1, -1)));

    int result = knapsack(n, maxWeight, maxVolume, n);
    cout << result << endl;
    return 0;
}
