#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

// Bài toán: Subset Sum / Knapsack với FFT
// Cho tập hợp các số A = {a1, a2, ..., an}.
// Tìm tất cả các tổng có thể tạo thành.
// Sử dụng Hàm sinh (Generating Function): P(x) = (x^a1 + 1)(x^a2 + 1)...
// Hoặc nếu số lượng mỗi loại nhiều: P(x) = product (1 + x^ai + x^2ai + ...)
// Nhân đa thức bằng FFT để đạt O(V log V) thay vì O(N*V).

typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}

int main() {
    // Ví dụ: Đa thức A đại diện cho tập {1, 2} -> x^1 + x^2
    // Đa thức B đại diện cho tập {2, 3} -> x^2 + x^3
    // Tích A*B sẽ cho biết các tổng tạo thành từ việc chọn 1 phần tử từ A và 1 từ B.
    cout << "FFT Knapsack template." << endl;
    return 0;
}
