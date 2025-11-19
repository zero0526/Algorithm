#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Minkowski Sum
// Cho 2 bao lồi P và Q. Tìm bao lồi của tập {p + q | p thuộc P, q thuộc Q}.
// Ứng dụng: Geometry DP, Game Theory.
// Thuật toán: Reorder các cạnh của P và Q theo góc cực, sau đó merge lại (như merge sort).
// Độ phức tạp: O(|P| + |Q|).

struct Point {
    long long x, y;
    Point operator+(const Point& o) const { return {x + o.x, y + o.y}; }
    Point operator-(const Point& o) const { return {x - o.x, y - o.y}; }
};

long long cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

void reorder_polygon(vector<Point>& P) {
    // Xoay polygon sao cho điểm thấp nhất trái nhất nằm đầu
    // ...
}

vector<Point> minkowski_sum(vector<Point> P, vector<Point> Q) {
    reorder_polygon(P);
    reorder_polygon(Q);
    P.push_back(P[0]); P.push_back(P[1]);
    Q.push_back(Q[0]); Q.push_back(Q[1]);
    
    vector<Point> result;
    result.push_back(P[0] + Q[0]);
    
    int i = 0, j = 0;
    while (i < P.size() - 2 || j < Q.size() - 2) {
        result.push_back(result.back() + 
            (cross_product(P[i+1]-P[i], Q[j+1]-Q[j]) >= 0 ? (P[i+1]-P[i]) : (Q[j+1]-Q[j])));
        // Logic merge chi tiết cần xử lý cẩn thận
        // ...
        if (cross_product(P[i+1]-P[i], Q[j+1]-Q[j]) >= 0) ++i;
        else ++j;
    }
    return result;
}

int main() {
    cout << "Minkowski Sum template." << endl;
    return 0;
}
