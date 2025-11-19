#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Bài toán: DP trên Aho-Corasick Automaton
// Đếm số chuỗi độ dài N không chứa bất kỳ mẫu nào trong tập P.
// Trạng thái DP: dp[len][u] = số chuỗi độ dài len kết thúc tại node u trên cây AC.

const int MAX_NODES = 1005;
const int SIGMA = 26;

struct AhoCorasick {
    int trie[MAX_NODES][SIGMA];
    int fail[MAX_NODES];
    bool is_end[MAX_NODES];
    int nodes_cnt = 1;

    void insert(string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!trie[u][v]) trie[u][v] = nodes_cnt++;
            u = trie[u][v];
        }
        is_end[u] = true;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < SIGMA; ++i) {
            if (trie[0][i]) q.push(trie[0][i]);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            is_end[u] |= is_end[fail[u]]; // Lan truyền trạng thái cấm
            for (int i = 0; i < SIGMA; ++i) {
                if (trie[u][i]) {
                    fail[trie[u][i]] = trie[fail[u]][i];
                    q.push(trie[u][i]);
                } else {
                    trie[u][i] = trie[fail[u]][i];
                }
            }
        }
    }
};

int main() {
    cout << "Aho-Corasick DP template." << endl;
    return 0;
}
