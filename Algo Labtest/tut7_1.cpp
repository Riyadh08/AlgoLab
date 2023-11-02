// 0/1 knapsack
#include<bits/stdc++.h>
using namespace std;

vector<int> weight;
vector<int> value;

int knapsack(int index, int capacity, vector<vector<int>>& dp) {
    if (index == 0) {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1) return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + knapsack(index - 1, capacity - weight[index], dp);

    int exclude = knapsack(index - 1, capacity, dp);

    dp[index][capacity] = max(exclude, include);

    return dp[index][capacity];
}

int main() {
    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        weight.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        value.push_back(x);
    }

    cout << knapsack(n - 1, maxWeight, dp); // Adjusted the function call index

    return 0;
}
