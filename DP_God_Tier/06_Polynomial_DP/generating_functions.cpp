#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Partition Number (Số cách phân hoạch số nguyên N)
// P(n) là hệ số của x^n trong khai triển:
// Product_{k=1 to inf} (1 / (1 - x^k))
// = Product (1 + x^k + x^2k + ...)
// Sử dụng Pentagonal Number Theorem để tính nhanh trong O(N sqrt N).

const int MOD = 1e9 + 7;

int partition_function(int n) {
    vector<int> p(n + 1, 0);
    p[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; ; ++k) {
            int pent1 = k * (3 * k - 1) / 2;
            int pent2 = k * (3 * k + 1) / 2;
            if (pent1 > i) break;
            
            if (k % 2 == 1) {
                p[i] = (p[i] + p[i - pent1]) % MOD;
                if (pent2 <= i) p[i] = (p[i] + p[i - pent2]) % MOD;
            } else {
                p[i] = (p[i] - p[i - pent1] + MOD) % MOD;
                if (pent2 <= i) p[i] = (p[i] - p[i - pent2] + MOD) % MOD;
            }
        }
    }
    return p[n];
}

int main() {
    int n = 10;
    cout << "Partitions of " << n << ": " << partition_function(n) << endl;
    return 0;
}
