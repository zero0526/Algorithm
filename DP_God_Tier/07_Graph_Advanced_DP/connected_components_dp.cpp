#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Đếm số đồ thị liên thông gồm N đỉnh (có dán nhãn).
// Hoặc đếm số chu trình Hamilton.
// Sử dụng Set Power Series hoặc Inclusion-Exclusion.
// Công thức truy hồi cơ bản:
// Total[n] = 2^(n*(n-1)/2)
// Connected[n] = Total[n] - Sum(C(n-1, k-1) * Connected[k] * Total[n-k]) với k từ 1 đến n-1.
// (Cố định đỉnh 1 thuộc thành phần liên thông kích thước k).

const int MOD = 1e9 + 7;
long long C[100][100];

void precompute() {
    for (int i = 0; i < 100; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {
    cout << "Connected Components DP template." << endl;
    return 0;
}
