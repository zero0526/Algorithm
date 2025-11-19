#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Bài toán: Slope Trick
// Quản lý hàm lồi f(x) dưới dạng các đoạn thẳng có hệ số góc tăng dần.
// Thường dùng cho bài toán: dp[i] = min(dp[i-1] + |x - a[i]|)
// Sử dụng 2 Priority Queue để lưu các điểm gãy (change points) của hàm.
// L: lưu các điểm gãy bên trái (slope < 0), R: lưu các điểm gãy bên phải (slope > 0).

priority_queue<long long> L; // Max heap
priority_queue<long long, vector<long long>, greater<long long>> R; // Min heap
long long min_val = 0; // Giá trị nhỏ nhất của hàm hiện tại

// Thêm hàm |x - a| vào hàm hiện tại
void add_abs(long long a) {
    // Hàm |x - a| có slope -1 với x < a, và +1 với x > a.
    // Ta push a vào cả L và R để duy trì tính chất.
    // Sau đó cân bằng lại để slope 0 nằm giữa top L và top R.
    
    L.push(a);
    R.push(a);
    
    long long l_top = L.top();
    long long r_top = R.top();
    
    if (l_top > r_top) {
        min_val += (l_top - r_top);
        L.pop(); R.pop();
        L.push(r_top);
        R.push(l_top);
    }
}

int main() {
    // Ví dụ: Bài toán làm cho dãy A thành dãy không giảm tốn ít chi phí nhất (với chi phí |Ai - Bi|)
    // (Thực ra bài đó dùng 1 PQ là đủ, nhưng đây là demo cấu trúc chung)
    
    vector<long long> A = {3, 2, 5, 1, 7};
    // Giả sử cần tìm x để min tổng |x - A[i]| (Median problem)
    for (long long x : A) {
        add_abs(x);
    }
    cout << "Min value: " << min_val << endl;
    return 0;
}
