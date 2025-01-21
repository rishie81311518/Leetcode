class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         int n = s.length();

    // Iterate through possible substring lengths
    for (int len = 1; len <= n / 2; ++len) {
        // Check if 'len' divides 'n' evenly
        if (n % len == 0) {
            string substring = s.substr(0, len); // Extract substring of length 'len'
            string repeated = "";

            // Construct a string by repeating the substring
            for (int i = 0; i < n / len; ++i) {
                repeated += substring;
            }

            // Check if the constructed string matches the original string
            if (repeated == s) {
                return true;
            }
        }
    }

    return false; 
        
    }
};