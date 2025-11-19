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
    // TODO: 
    int n1= text1.size();
    int n2= text2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=1; i<=n1; i++){
      for(int j=1;j<=n2;j++){
         if(text1[i-1]==text2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
         }else{
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
         }
      }
    }    
    return dp[n1][n2];
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    cout << "LCS length: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
