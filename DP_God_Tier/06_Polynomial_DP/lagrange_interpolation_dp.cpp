#include <iostream>
#include <vector>

using namespace std;

// Bài toán: Tìm giá trị DP[N] với N cực lớn (10^18).
// Nếu DP[i] là một đa thức bậc K theo i.
// Ta chỉ cần tính K+2 giá trị đầu tiên (DP[0]...DP[K+1]).
// Sau đó dùng Lagrange Interpolation để tìm DP[N].

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

long long lagrange_interpolation(const vector<long long>& y, long long x) {
    int k = y.size() - 1;
    if (x <= k) return y[x];
    
    // Tính pre[i] = (x-0)(x-1)...(x-(i-1))
    // suf[i] = (x-(i+1))...(x-k)
    // ... (Implementation omitted for brevity)
    
    return 0; // Placeholder
}

int main() {
    // Ví dụ: Tổng bình phương 1^2 + ... + n^2 là đa thức bậc 3.
    // Cần 4 điểm: y[0]=0, y[1]=1, y[2]=5, y[3]=14.
    vector<long long> y = {0, 1, 5, 14};
    long long N = 100;
    cout << "Lagrange Interpolation template." << endl;
    return 0;
}
