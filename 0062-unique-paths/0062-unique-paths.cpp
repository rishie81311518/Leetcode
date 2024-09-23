class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int k = (m-1 < n-1) ? m-1 : n-1;
        for (int i = 1; i <= k; ++i) {
            result = result * (m + n - 2 - i + 1) / i;
        }
        
        return static_cast<int>(result); 
    }
};