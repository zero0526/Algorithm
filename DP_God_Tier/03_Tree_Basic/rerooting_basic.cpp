#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Rerooting DP (Basic)
// Tính tổng khoảng cách từ tất cả các node đến node gốc hiện tại.
// Làm cho TẤT CẢ các node (nếu mỗi node lần lượt là gốc).
// Bước 1: DFS 1 (Bottom-up) tính subtree_size và dp[u] (tổng kc trong subtree u).
// Bước 2: DFS 2 (Top-down) tính ans[u] khi dời gốc từ p sang u.

int n;
vector<vector<int>> adj;
vector<long long> dp, sz;
vector<long long> ans;

void dfs1(int u, int p) {
    sz[u] = 1;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}

void dfs2(int u, int p) {
    ans[u] = dp[u]; // dp[u] lúc này đã được cập nhật đầy đủ từ cha (trong bước dời gốc)
    // Tuy nhiên, cách viết chuẩn rerooting thường là:
    // ans[root] = dp[root] (sau dfs1)
    // Khi move từ u -> v:
    // dp[u] -= (dp[v] + sz[v])
    // sz[u] -= sz[v]
    // sz[v] += sz[u]
    // dp[v] += (dp[u] + sz[u])
    // ... rồi dfs2(v, u) ... rồi backtrack lại.
    
    // Ở đây ta dùng công thức tổng quát:
    // ans[v] = ans[u] - sz[v] + (n - sz[v])
    // Giải thích: Khi dời từ u sang v, v tiến gần hơn 1 bước tới sz[v] node (giảm sz[v]),
    // và xa hơn 1 bước tới (n - sz[v]) node còn lại (tăng n - sz[v]).
    
    for (int v : adj[u]) {
        if (v == p) continue;
        // Công thức chuyển đổi nhanh cho bài toán tổng khoảng cách
        long long old_ans_u = ans[u]; // Thực ra ans[u] đã tính xong
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}

int main() {
    n = 4; // 0-1, 1-2, 2-3 (Line graph)
    adj.resize(n);
    adj[0] = {1}; adj[1] = {0, 2}; adj[2] = {1, 3}; adj[3] = {2};
    
    dp.resize(n); sz.resize(n); ans.resize(n);
    
    dfs1(0, -1);
    ans[0] = dp[0]; // Gốc 0 đúng bằng dp[0]
    dfs2(0, -1);
    
    for(int i=0; i<n; ++i) cout << "Sum dist from " << i << ": " << ans[i] << endl;
    
    return 0;
}
