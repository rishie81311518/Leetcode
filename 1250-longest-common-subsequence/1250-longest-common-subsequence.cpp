class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create a 2D dp array with dimensions (m+1)x(n+1), initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp array
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If characters match, add 1 to the result of the previous characters
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If characters do not match, take the maximum of ignoring one character
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The answer is the length of the longest common subsequence
        return dp[m][n];
    }
};
