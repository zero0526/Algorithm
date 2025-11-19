#include <iostream>
#include <vector>

using namespace std;

/*
BÀI TOÁN: Unique Paths (LeetCode 62)
Một robot nằm ở góc trên cùng bên trái của lưới m x n (điểm (0, 0)).
Robot muốn di chuyển đến góc dưới cùng bên phải (điểm (m-1, n-1)).
Robot chỉ có thể di chuyển xuống dưới hoặc sang phải tại bất kỳ thời điểm nào.
Hỏi có bao nhiêu đường đi duy nhất?

TEST CASES:
1. Input: m = 3, n = 7
   Output: 28

2. Input: m = 3, n = 2
   Output: 3
   Giải thích:
   - Phải -> Xuống -> Xuống
   - Xuống -> Phải -> Xuống
   - Xuống -> Xuống -> Phải
*/

int uniquePaths(int m, int n) {
    // TODO: Viết code của bạn ở đây
    return -1;
}

int main() {
    int m = 3, n = 7;
    cout << "Unique Paths (" << m << "x" << n << "): " << uniquePaths(m, n) << endl;
    return 0;
}
