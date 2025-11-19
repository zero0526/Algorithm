#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BÀI TOÁN: Longest Increasing Subsequence (LIS)
Cho một mảng số nguyên nums.
Trả về độ dài của dãy con tăng dài nhất.
Dãy con tăng nghiêm ngặt.

TEST CASES:
1. Input: nums = {10, 9, 2, 5, 3, 7, 101, 18}
   Output: 4
   Giải thích: Dãy con tăng dài nhất là {2, 3, 7, 101}, độ dài 4.

2. Input: nums = {0, 1, 0, 3, 2, 3}
   Output: 4
   Giải thích: Dãy con tăng dài nhất là {0, 1, 2, 3}, độ dài 4.

3. Input: nums = {7, 7, 7, 7}
   Output: 1
   Giải thích: Dãy con tăng dài nhất chỉ có 1 phần tử.
*/

int lengthOfLIS(vector<int>& nums) {
    // TODO: Viết code của bạn ở đây
    // Gợi ý: DP O(N^2) là đủ cho người mới bắt đầu.
    // Thử thách: Cải tiến lên O(NlogN) dùng Binary Search.
    return -1;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lengthOfLIS(nums) << endl;
    return 0;
}
