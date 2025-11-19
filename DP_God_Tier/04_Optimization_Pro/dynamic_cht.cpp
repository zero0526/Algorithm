#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Bài toán: Dynamic Convex Hull Trick (Fully Dynamic)
// Quản lý tập các đường thẳng y = mx + c.
// Truy vấn: Tìm max(mx + c) tại x cho trước.
// Hỗ trợ thêm đường thẳng mới bất kỳ.
// Sử dụng std::set để duy trì bao lồi.

const long long is_query = -(1LL<<62);

struct Line {
    long long m, c;
    mutable function<const Line*()> succ;
    bool operator<(const Line& o) const {
        if (o.c != is_query) return m < o.m;
        const Line* s = succ();
        if (!s) return 0;
        long long x = o.m;
        return c - s->c < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->c <= z->c;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->c <= x->c;
        return (x->c - y->c) * (long double)(z->m - y->m) >= (y->c - z->c) * (long double)(y->m - x->m);
    }
    void insert_line(long long m, long long c) {
        auto z = insert({m, c});
        y->succ = [=] { return z == end() ? 0 : &*z; };
        if (bad(z)) { erase(z); return; }
        while (next(z) != end() && bad(next(z))) erase(next(z));
        while (z != begin() && bad(prev(z))) erase(prev(z));
    }
    long long query(long long x) {
        auto l = *lower_bound((Line){x, is_query});
        return l.m * x + l.c;
    }
};

int main() {
    HullDynamic cht;
    cht.insert_line(2, 3); // y = 2x + 3
    cht.insert_line(-1, 10); // y = -x + 10
    
    cout << "Max at x=1: " << cht.query(1) << endl; // max(5, 9) = 9
    cout << "Max at x=5: " << cht.query(5) << endl; // max(13, 5) = 13
    return 0;
}
