#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Bài toán: Traveling Salesman Problem (TSP) - Bitmask DP
// Tìm chu trình ngắn nhất đi qua tất cả thành phố đúng 1 lần và quay về xuất phát.
// N <= 20.

const int INF = 1e9;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Quay về 0
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) { // Nếu chưa thăm city
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    n = 4;
    dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    dp.assign(1 << n, vector<int>(n, -1));
    cout << "Min TSP Cost: " << tsp(1, 0) << endl; // Bắt đầu từ thành phố 0, mask = 1 (0001)
    return 0;
}
