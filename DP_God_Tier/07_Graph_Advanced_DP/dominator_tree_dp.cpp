#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Dominator Tree
// Xây dựng cây thống trị cho đồ thị có hướng.
// Node u thống trị v nếu mọi đường đi từ Start đến v đều phải đi qua u.
// Sau khi dựng cây, ta có thể DP trên cây này để trả lời các truy vấn về tính thống trị.
// Thuật toán Lengauer-Tarjan O(M log N) hoặc O(M alpha N).

const int MAXN = 100005;
vector<int> adj[MAXN], rev_adj[MAXN], dom_tree[MAXN];
int sdom[MAXN], idom[MAXN], parent[MAXN], dsu[MAXN], label[MAXN];
int arr[MAXN], rev[MAXN], t;

int find(int u, int x = 0) {
    if (u == dsu[u]) return x ? -1 : u;
    int v = find(dsu[u], x + 1);
    if (v < 0) return u;
    if (sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
    dsu[u] = v;
    return x ? v : label[u];
}

void union_sets(int u, int v) {
    dsu[v] = u;
}

void dfs(int u) {
    t++; arr[u] = t; rev[t] = u;
    label[t] = t; sdom[t] = t; dsu[t] = t;
    for (int v : adj[u]) {
        if (!arr[v]) {
            dfs(v);
            parent[arr[v]] = arr[u];
        }
        rev_adj[arr[v]].push_back(arr[u]);
    }
}

int main() {
    cout << "Dominator Tree template (Lengauer-Tarjan)." << endl;
    return 0;
}
