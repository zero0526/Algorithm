#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Dynamic DP (DDP)
// Cho cây có trọng số tại mỗi node.
// Truy vấn 1: Cập nhật trọng số của node u.
// Truy vấn 2: Tìm tập độc lập có tổng trọng số lớn nhất (Maximum Independent Set).
// Giải pháp: HLD + Matrix Multiplication trên Segment Tree.

const int INF = 1e9;

struct Matrix {
    long long mat[2][2];
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = -INF;
    }
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C.mat[i][j] = max(C.mat[i][j], A.mat[i][k] + B.mat[k][j]);
            }
        }
    }
    return C;
}

// HLD variables
vector<vector<int>> adj;
vector<int> parent, depth, heavy, head, pos;
int cur_pos;
int n;
vector<long long> val; // Weight of nodes

// DP variables
// f[u][0]: Max IS in subtree u, u not chosen
// f[u][1]: Max IS in subtree u, u chosen
// g[u][0]: Sum of max(f[v][0], f[v][1]) for light children v
// g[u][1]: Sum of f[v][0] for light children v

// Segment Tree to store matrices
// Matrix for node u:
// [ g[u][0]   g[u][0] ]
// [ g[u][1]   -INF    ]
// Multiplication order matters!

int main() {
    cout << "Dynamic DP with HLD template structure." << endl;
    cout << "Requires full HLD implementation and Segment Tree of Matrices." << endl;
    return 0;
}
