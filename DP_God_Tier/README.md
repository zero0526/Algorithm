# Lộ trình học Quy hoạch động (DP) - God-Tier Edition

Chào mừng bạn đến với "Địa ngục" của Quy hoạch động. Đây là lộ trình từ cơ bản đến cấp độ Grandmaster/IOI, bao gồm những kỹ thuật tối ưu hóa và toán học khó nhất trong lập trình thi đấu.

## Cấu trúc thư mục

### Level 1-3: Warm-up (Khởi động)
- **01_Classic**: Các bài toán kinh điển (Fibonacci, LCS, LIS). Nền tảng tư duy DP.
- **02_Intermediate**: Knapsack, Matrix Chain, Bitmask cơ bản.
- **03_Tree_Basic**: DP trên cây cơ bản (Diameter, Rerooting đơn giản).

### Level 4: Optimization Hell (Tối ưu hóa nâng cao)
Nơi bắt đầu của sự đau khổ. Giảm độ phức tạp từ O(N^2) xuống O(N) hoặc O(NlogN).
- **Convex Hull Trick (CHT)**: Tối ưu hàm bậc nhất.
- **Slope Trick**: Quản lý hàm lồi bằng Priority Queue.
- **Knuth/Yao Opt**: Tối ưu DP trên khoảng (tứ giác).
- **Alien's Trick**: WQS Binary Search (Lagrange Multiplier).

### Level 5: DP on Heavy Data Structures
Khi DP kết hợp với Segment Tree, HLD, Centroid Decomposition.
- **Dynamic DP (DDP)**: Cập nhật điểm, truy vấn DP trên cây (HLD + Matrix).
- **Segment Tree Beats**: Chmin/Chmax history.

### Level 6: Polynomials & Generating Functions
Ranh giới giữa Code và Toán.
- **FFT Knapsack**: Cái túi O(VlogV) dùng tích chập.
- **Generating Functions**: Hàm sinh, số Partition.
- **Lagrange Interpolation**: Tìm giá trị DP tại N=10^18.

### Level 7: Advanced Graphs
- **Aho-Corasick DP**: DP trên Automaton.
- **Dominator Tree**: Cây thống trị.
- **Connected Components**: Đếm đồ thị (Set Power Series).

### Level 8: Math God (Đại số & Tổ hợp)
- **Matrix Exponentiation**: Nhân ma trận trên vành, ma trận thưa.
- **Linear Basis**: XOR Basis.
- **Subset Convolution**: O(N^2 2^N) thay vì 3^N.

### Level 9: Geometry DP
- **Minkowski Sum**: Cộng bao lồi.
- **Rotating Calipers**: Thước kẹp xoay.

## Yêu cầu tiên quyết (Prerequisites)
Để sống sót qua Level 4-9, bạn CẦN phải thành thạo:
1. **Cấu trúc dữ liệu**: Segment Tree (Lazy), Fenwick Tree, DSU.
2. **Đồ thị**: DFS/BFS, Dijkstra, Flow (Max Flow Min Cut).
3. **Toán**:
   - Số học module (nghịch đảo, lũy thừa).
   - Đại số tuyến tính (Nhân ma trận, Gaussian elimination).
   - Số phức (cho FFT).
   - Tổ hợp (C(n,k), Nguyên lý bao hàm-loại trừ).

## Tài liệu tham khảo (Hardcore)
- **CP-Algorithms**: "Kinh thánh" cho thuật toán.
- **VNOI Wiki & Admin Blog**: Tài liệu tiếng Việt chất lượng cao.
- **Codeforces Gym**: Petrozavodsk Contests.
- **USACO Guide Platinum/Advanced**.

Chúc may mắn! Bạn sẽ cần nó.
