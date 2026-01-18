class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        vector<vector<int>> colSum(m + 1, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }
        
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (isMagic(grid, rowSum, colSum, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        
        return 1;
    }
    
private:
    bool isMagic(vector<vector<int>>& grid, vector<vector<int>>& rowSum, 
                 vector<vector<int>>& colSum, int r, int c, int k) {
        int target = rowSum[r][c + k] - rowSum[r][c];
        
        for (int i = r; i < r + k; i++) {
            if (rowSum[i][c + k] - rowSum[i][c] != target) {
                return false;
            }
        }
        
        for (int j = c; j < c + k; j++) {
            if (colSum[r + k][j] - colSum[r][j] != target) {
                return false;
            }
        }
        
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[r + i][c + i];
            diag2 += grid[r + i][c + k - 1 - i];
        }
        
        return diag1 == target && diag2 == target;
    }
};