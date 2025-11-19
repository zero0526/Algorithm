#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Fast Subset Convolution
// Tính h[S] = sum(f[A] * g[B]) với A U B = S và A giao B = rỗng.
// Độ phức tạp O(N^2 * 2^N) thay vì O(3^N).
// Sử dụng Ranked Mobius Transform (FMT thêm chiều kích thước tập hợp).

// dp[mask][i]: tổng các f[sub] sao cho sub là con của mask VÀ |sub| = i.

const int N = 20; // Số bit
int f[1 << N][N + 1];
int g[1 << N][N + 1];
int h[1 << N][N + 1];

void fmt(int a[][N + 1], bool inv) {
    for (int i = 0; i < N; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (mask & (1 << i)) {
                for (int j = 0; j <= N; ++j) {
                    if (!inv) a[mask][j] += a[mask ^ (1 << i)][j];
                    else a[mask][j] -= a[mask ^ (1 << i)][j];
                }
            }
        }
    }
}

int main() {
    cout << "Fast Subset Convolution template." << endl;
    // 1. Khởi tạo f[mask][popcount(mask)] = val
    // 2. FMT(f, false), FMT(g, false)
    // 3. h[mask][k] = sum(f[mask][i] * g[mask][k-i])
    // 4. FMT(h, true)
    // 5. Kết quả là h[mask][popcount(mask)]
    return 0;
}
