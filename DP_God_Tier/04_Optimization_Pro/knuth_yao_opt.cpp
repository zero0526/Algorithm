#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Bài toán: Knuth Optimization
// Áp dụng cho DP dạng: dp[i][j] = min(dp[i][k] + dp[k][j] + cost(i, j)) với i < k < j
// Điều kiện: opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
// (Bất đẳng thức tứ giác của hàm cost)
// Giảm độ phức tạp từ O(N^3) xuống O(N^2).

int n;
vector<long long> a;
vector<long long> pref;
vector<vector<long long>> dp;
vector<vector<int>> opt;

long long cost(int i, int j) {
    return pref[j] - pref[i]; // Ví dụ: cost là tổng đoạn từ i đến j-1
}

void solve() {
    // Khởi tạo
    for (int i = 0; i < n; ++i) {
        dp[i][i + 1] = 0;
        opt[i][i + 1] = i;
    }

    // DP
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len;
            dp[i][j] = 1e18;
            int start_k = opt[i][j - 1];
            int end_k = opt[i + 1][j];
            
            for (int k = start_k; k <= end_k && k < j; ++k) {
                // Lưu ý: k chạy từ opt[i][j-1] đến opt[i+1][j]
                // Đây là mấu chốt của Knuth Opt.
                long long val = dp[i][k] + dp[k][j] + cost(i, j);
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    opt[i][j] = k;
                }
            }
        }
    }
}

int main() {
    // Ví dụ: Optimal Binary Search Tree hoặc Stone Merging
    n = 4;
    a = {10, 20, 30, 40}; // Trọng số
    pref.resize(n + 1, 0);
    for(int i=0; i<n; ++i) pref[i+1] = pref[i] + a[i];
    
    dp.assign(n + 1, vector<long long>(n + 1));
    opt.assign(n + 1, vector<int>(n + 1));
    
    solve();
    cout << "Min Cost: " << dp[0][n] << endl;
    return 0;
}
