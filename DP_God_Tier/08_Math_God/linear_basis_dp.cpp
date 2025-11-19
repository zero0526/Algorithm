#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: Linear Basis (XOR Basis)
// Cho tập N số. Tìm tập con có XOR lớn nhất, hoặc XOR thứ K.
// Cơ sở tuyến tính (Basis) là tập hợp nhỏ nhất các số có thể tạo ra mọi giá trị XOR của tập ban đầu.
// Kích thước Basis <= log(Max_Value) (khoảng 60 với long long).

struct LinearBasis {
    vector<long long> basis;
    
    void insert(long long mask) {
        for (long long b : basis) {
            mask = min(mask, mask ^ b);
        }
        if (mask > 0) {
            basis.push_back(mask);
            sort(basis.rbegin(), basis.rend());
        }
    }
    
    long long max_xor() {
        long long ans = 0;
        for (long long b : basis) {
            ans = max(ans, ans ^ b);
        }
        return ans;
    }
};

int main() {
    LinearBasis lb;
    lb.insert(10);
    lb.insert(20);
    lb.insert(15);
    cout << "Max XOR: " << lb.max_xor() << endl;
    return 0;
}
