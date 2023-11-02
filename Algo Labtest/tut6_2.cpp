//Coin change
#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
vector<int> coins;
vector<int> quantities;
int n, w;
const int INF = 1e9;

int f(int sum, int i) {
    if (sum == w) return 0;
    if (i >= n || sum > w) return INF;

    if (dp[sum][i] != -1) return dp[sum][i];

    int minCoins = INF;

    // Try taking different quantities of the current coin.
    for (int take = 0; take <= quantities[i]; take++) {
        if (sum + take * coins[i] <= w) {
            minCoins = min(minCoins, f(sum + take * coins[i], i + 1) + take);
        }
    }

    dp[sum][i] = minCoins;
    return dp[sum][i];
}

int main() {
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int steps;
        cin >> steps;
        quantities.push_back(steps);
    }
    int result = f(0, 0);

    if (result == INF) {
        cout << "Not possible to make the required sum." << endl;
    }
    else {
        cout << "Minimum number of coins needed: " << result << endl;
    }

    return 0;
}
