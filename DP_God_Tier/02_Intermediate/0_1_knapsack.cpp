#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài toán: 0/1 Knapsack
// Có N đồ vật, mỗi vật có trọng lượng w[i] và giá trị v[i].
// Cái túi chịu được trọng lượng tối đa W.
// Tìm tổng giá trị lớn nhất.

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
}

// Tối ưu không gian O(W)
int knapsack_opt(int W, vector<int>& wt, vector<int>& val, int n) {
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << "Max Value: " << knapsack_opt(W, wt, val, n) << endl;
    return 0;
}
