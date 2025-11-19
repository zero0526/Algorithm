#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Bài toán: Digit DP Basic
// Đếm số lượng số nguyên x trong khoảng [0, R] sao cho tổng các chữ số của x bằng S.

string S_str;
int target_sum;
long long memo[20][200][2]; // pos, current_sum, tight

long long dp(int pos, int current_sum, bool tight) {
    if (current_sum > target_sum) return 0;
    if (pos == S_str.length()) {
        return current_sum == target_sum;
    }
    if (memo[pos][current_sum][tight] != -1) return memo[pos][current_sum][tight];

    long long ans = 0;
    int limit = tight ? (S_str[pos] - '0') : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        bool new_tight = tight && (digit == limit);
        ans += dp(pos + 1, current_sum + digit, new_tight);
    }

    return memo[pos][current_sum][tight] = ans;
}

long long solve(long long R, int S) {
    S_str = to_string(R);
    target_sum = S;
    memset(memo, -1, sizeof(memo));
    return dp(0, 0, true);
}

int main() {
    long long R = 100;
    int S = 5;
    cout << "Count numbers <= " << R << " with digit sum " << S << ": " << solve(R, S) << endl;
    return 0;
}
