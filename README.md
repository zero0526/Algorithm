# Level 1: Classic DP Problems (Bài toán kinh điển)

Thư mục này chứa các bài toán nền tảng nhất của Quy hoạch động. Bạn cần nắm vững các dạng này trước khi qua Level 2.

## Phân loại bài tập

Để dễ học, chúng ta chia các bài toán kinh điển thành 3 nhóm chính:

### 1. Dạng 1: Cơ bản 1 chiều (Basic 1D)
Đây là dạng đơn giản nhất. Trạng thái tại bước `i` thường chỉ phụ thuộc vào một vài bước ngay trước đó (`i-1`, `i-2`).
*Mục tiêu: Hiểu khái niệm "trạng thái" và "chuyển trạng thái".*

*   **[Fibonacci](fibonacci.cpp)**: Bài toán nhập môn.
    *   Công thức: `dp[i] = dp[i-1] + dp[i-2]`
*   **[Frog Jump](frog_jump.cpp)** (Frog 1 - AtCoder):
    *   Mô tả: Ếch nhảy từ đá `i` sang `i+1` hoặc `i+2` với chi phí nhất định.
    *   Công thức: `dp[i] = min(dp[i-1] + cost1, dp[i-2] + cost2)`

### 2. Dạng 2: Quy hoạch động trên lưới (Grid DP)
Bài toán di chuyển trên ma trận (thường là từ góc trên-trái xuống góc dưới-phải).
*Mục tiêu: Làm quen với DP 2 chiều.*

*   **[Unique Paths](unique_paths.cpp)** (LeetCode 62):
    *   Mô tả: Đếm số cách đi từ `(0,0)` đến `(m,n)`.
    *   Công thức: `dp[i][j] = dp[i-1][j] + dp[i][j-1]` (Tổng số cách từ ô trên và ô trái).

### 3. Dạng 3: Dãy con & Xử lý chuỗi (Sequences & Strings)
Các bài toán liên quan đến việc chọn các phần tử trong dãy hoặc so sánh hai chuỗi. Đây là dạng quan trọng nhất.

*   **[Longest Common Subsequence (LCS)](longest_common_subsequence.cpp)**:
    *   Mô tả: Tìm độ dài xâu con chung dài nhất của 2 chuỗi.
    *   Công thức:
        *   Nếu `s1[i] == s2[j]`: `dp[i][j] = 1 + dp[i-1][j-1]`
        *   Nếu khác: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
*   **[Longest Increasing Subsequence (LIS)](longest_increasing_subsequence.cpp)**:
    *   Mô tả: Tìm độ dài dãy con tăng dài nhất.
    *   Công thức: `dp[i] = max(dp[j] + 1)` với mọi `j < i` mà `nums[j] < nums[i]`.

## Lộ trình học đề xuất
1.  **Fibonacci**: Viết cả 3 cách (Đệ quy, Memoization, Tabulation).
2.  **Frog Jump**: Hiểu cách tính chi phí tối thiểu.
3.  **Unique Paths**: Hiểu cách trạng thái lan truyền trên lưới.
4.  **LCS**: Hiểu DP 2 chiều trên 2 chuỗi khác nhau.
5.  **LIS**: Hiểu DP phụ thuộc vào tất cả các trạng thái trước đó (vòng lặp lồng nhau).
