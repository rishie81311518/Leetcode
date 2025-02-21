class Solution {
public:
    int strStr(string haystack, string needle) {
      int hLen = haystack.size();
    int nLen = needle.size();

    // Edge case: empty needle
    if (nLen == 0) return 0;

    // Loop through haystack
    for (int i = 0; i <= hLen - nLen; ++i) {
        int j = 0;
        
        // Compare needle with current substring in haystack
        while (j < nLen && haystack[i + j] == needle[j]) {
            ++j;
        }

        // If full needle is matched
        if (j == nLen) return i;
    }

    // Needle not found
    return -1;

        
    }
};




