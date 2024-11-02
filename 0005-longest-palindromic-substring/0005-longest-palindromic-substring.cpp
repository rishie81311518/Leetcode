class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        // Edge case: if the string is empty or has one character, return s
        if (n < 2) return s;

        // DP table to store whether s[i:j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLength = 1; // Length of the longest palindromic substring found
        int start = 0;     // Starting index of the longest palindromic substring

        // All substrings of length 1 are palindromic
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings longer than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index of the current substring

                // Check if s[i:j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, maxLength);
    }
};
