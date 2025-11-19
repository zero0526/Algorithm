#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Divide and Conquer on Tree (Centroid Decomposition)
// Đếm số đường đi trên cây có độ dài <= K.
// Hoặc tối ưu DP trên cây: dp[u] phụ thuộc vào các node trong subtree.

vector<vector<int>> adj;
vector<bool> removed;
vector<int> sz;
int n;

void calc_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            calc_size(v, u);
            sz[u] += sz[v];
        }
    }
}

int find_centroid(int u, int p, int tree_size) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sz[v] > tree_size / 2) {
            return find_centroid(v, u, tree_size);
        }
    }
    return u;
}

void decompose(int u) {
    calc_size(u, -1);
    int centroid = find_centroid(u, -1, sz[u]);
    
    // Xử lý các đường đi đi qua centroid
    // ... (Logic DP hoặc đếm ở đây)
    
    removed[centroid] = true;
    for (int v : adj[centroid]) {
        if (!removed[v]) {
            decompose(v);
        }
    }
}

int main() {
    n = 5;
    adj.resize(n + 1);
    removed.assign(n + 1, false);
    sz.resize(n + 1);
    
    // Build graph...
    
    decompose(1);
    cout << "Centroid Decomposition structure ready." << endl;
    return 0;
}
