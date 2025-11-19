#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Segment Tree Beats
// Hỗ trợ các thao tác range chmin (a[i] = min(a[i], x)), range sum.
// Ứng dụng trong DP: Tối ưu hóa chuyển trạng thái trên đoạn.
// Ví dụ: dp[i] = min(dp[j] + cost) với j trong khoảng nào đó.

const long long INF = 1e18;

struct Node {
    long long sum;
    long long max1, max2;
    int max_cnt;
};

// Cần implement lazy propagation phức tạp (Jiry's Trick)
// 1. Nếu x >= max1: return (không làm gì)
// 2. Nếu max2 < x < max1: cập nhật max1 thành x, update sum, push lazy
// 3. Nếu x <= max2: đệ quy xuống con

int main() {
    cout << "Segment Tree Beats template." << endl;
    cout << "Used for historical sums and range chmin/chmax updates." << endl;
    return 0;
}
