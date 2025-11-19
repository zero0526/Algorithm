#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/*
BÀI TOÁN: Fibonacci Number
Tìm số Fibonacci thứ n.
Định nghĩa:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) với n > 1.

TEST CASES:
1. Input: n = 2
   Output: 1

2. Input: n = 3
   Output: 2

3. Input: n = 4
   Output: 3

4. Input: n = 10
   Output: 55
*/

long long solve(int n) {
    // TODO: Viết code của bạn ở đây
    // Gợi ý: Có thể dùng Đệ quy có nhớ (Memoization) hoặc Quy hoạch động (Tabulation)
    ll f1=1, f2=1;
    if(n==1)return f1;
    else if(n==2) return f2;
    for(int i=3; i<=n;i++){
      ll temp= f2;
      f2+=f1;
      f1=temp;
    }
    return f2;
}

int main() {
    int n;
    if (cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}
