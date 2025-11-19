#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
BÀI TOÁN: Longest Common Subsequence (LCS)
Cho hai chuỗi văn bản text1 và text2. Trả về độ dài của dãy con chung dài nhất của chúng.
Dãy con chung là dãy ký tự xuất hiện trong cả hai chuỗi theo đúng thứ tự (không cần liên tiếp).

TEST CASES:
1. Input: text1 = "abcde", text2 = "ace" 
   Output: 3  
   Giải thích: LCS là "ace".

2. Input: text1 = "abc", text2 = "abc"
   Output: 3
   Giải thích: LCS là "abc".

3. Input: text1 = "abc", text2 = "def"
   Output: 0
   Giải thích: Không có dãy con chung.
*/

int longestCommonSubsequence(string text1, string text2) {
    // TODO: Viết code của bạn ở đây
    return -1;
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "LCS length: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
