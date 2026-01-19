class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int left = 0, right = min(m, n);
        int result = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(canFindSquare(prefix, mid, threshold, m, n)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    bool canFindSquare(vector<vector<int>>& prefix, int size, int threshold, int m, int n) {
        for(int i = size; i <= m; i++) {
            for(int j = size; j <= n; j++) {
                int sum = prefix[i][j] - prefix[i-size][j] - prefix[i][j-size] + prefix[i-size][j-size];
                if(sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
};