#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Alien's Trick (WQS Binary Search / Lagrange Multiplier)
// Dùng khi cần tối ưu bài toán: Tìm giá trị tốt nhất khi chọn ĐÚNG K phần tử.
// Hàm kết quả f(k) phải lồi (convex) hoặc lõm (concave).
// Ý tưởng: Thay vì cố định K, ta thêm một chi phí 'lambda' cho mỗi lần chọn.
// Tìm lambda sao cho số lượng phần tử tối ưu được chọn xấp xỉ K.

const long long INF = 1e18;

struct Result {
    long long val;
    int cnt;
};

int n, k;
vector<long long> a;

// Hàm giải bài toán không ràng buộc K, nhưng mỗi lần chọn tốn thêm chi phí lambda
Result solve_with_penalty(long long lambda) {
    // Ví dụ: Chọn k đoạn con sao cho tổng lớn nhất.
    // dp[i] = max(dp[i-1], dp[j] + sum(j+1...i) - lambda)
    // Đây chỉ là ví dụ giả định.
    
    // Giả sử bài toán: Chọn k số sao cho tổng lớn nhất (tầm thường, nhưng để demo)
    // Thực tế thường là bài toán phức tạp hơn như k đoạn con, k cạnh trên cây...
    
    // Demo logic:
    long long current_val = 0;
    int current_cnt = 0;
    // ... logic DP O(N) ở đây ...
    
    return {current_val, current_cnt};
}

int main() {
    // Binary search lambda
    long long low = 0, high = 1e9;
    long long ans = -1;
    
    // Giả sử hàm lồi
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        Result res = solve_with_penalty(mid);
        
        if (res.cnt >= k) { // Nếu chọn quá nhiều hoặc đủ, tăng phạt để giảm số lượng
            ans = res.val + mid * k; // Khôi phục giá trị thực
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << "Optimal value with exactly " << k << " items: " << ans << endl;
    return 0;
}
