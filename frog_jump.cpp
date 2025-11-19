#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
BÀI TOÁN: Frog Jump (Frog 1 - AtCoder)
Có N hòn đá, đánh số 1, 2, ..., N. Độ cao hòn đá i là h[i].
Con ếch đang ở hòn đá 1. Nó muốn nhảy đến hòn đá N.
Từ hòn đá i, ếch có thể nhảy tới:
- Hòn đá i + 1: Chi phí |h[i] - h[i+1]|
- Hòn đá i + 2: Chi phí |h[i] - h[i+2]|
Tìm tổng chi phí tối thiểu để đến được hòn đá N.

TEST CASES:
1. Input: N = 4, h = {10, 30, 40, 20}
   Output: 30
   Giải thích: 1 -> 2 -> 4. Chi phí: |10-30| + |30-20| = 20 + 10 = 30.

2. Input: N = 2, h = {10, 10}
   Output: 0
   Giải thích: 1 -> 2. Chi phí: |10-10| = 0.

3. Input: N = 6, h = {30, 10, 60, 10, 60, 50}
   Output: 40
   Giải thích: 1 -> 3 -> 5 -> 6. Chi phí: |30-60| + |60-60| + |60-50| = 30 + 0 + 10 = 40.
*/

int solve(int N, vector<int>& h) {
    if (N == 0) return 0;
    vector<int> dp(N, 0);
    dp[0] = 0;
    if (N > 1) dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    return dp[N-1];
}

int main() {
    int N;
    if (cin >> N) {
        vector<int> h(N);
        for (int i = 0; i < N; ++i) cin >> h[i];
        cout << solve(N, h) << endl;
    }
    return 0;
}
