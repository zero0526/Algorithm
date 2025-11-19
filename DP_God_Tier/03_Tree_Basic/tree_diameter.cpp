#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Tree Diameter
// Tìm đường kính của cây (khoảng cách xa nhất giữa 2 node bất kỳ).
// Cách DP: Tại mỗi node u, tính chiều cao lớn nhất (max1) và lớn nhì (max2) của các cây con.
// Diameter qua u = max1 + max2.

int n;
vector<vector<int>> adj;
int diameter = 0;

int dfs(int u, int p) {
    int max1 = 0; // Chiều cao lớn nhất
    int max2 = 0; // Chiều cao lớn nhì

    for (int v : adj[u]) {
        if (v == p) continue;
        int h = dfs(v, u);
        if (h > max1) {
            max2 = max1;
            max1 = h;
        } else if (h > max2) {
            max2 = h;
        }
    }
    diameter = max(diameter, max1 + max2);
    return max1 + 1;
}

int main() {
    n = 5;
    adj.resize(n + 1);
    // 1-2, 1-3, 3-4, 3-5
    adj[1] = {2, 3}; adj[2] = {1};
    adj[3] = {1, 4, 5}; adj[4] = {3}; adj[5] = {3};

    dfs(1, 0);
    cout << "Tree Diameter: " << diameter << endl;
    return 0;
}
