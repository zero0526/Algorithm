#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Bài toán: Matrix Chain Multiplication
// Cho chuỗi ma trận A1, A2, ..., An. Tìm cách đặt ngoặc để số phép nhân vô hướng là ít nhất.
// Kích thước: p[0]...p[n] (Ai kích thước p[i-1] x p[i])

int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l là độ dài chuỗi ma trận (từ 2 đến n)
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> p = {1, 2, 3, 4}; // A1: 1x2, A2: 2x3, A3: 3x4
    cout << "Min Multiplications: " << matrixChainOrder(p) << endl;
    return 0;
}
