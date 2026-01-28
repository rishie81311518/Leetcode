class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k > 0 && grid[0][0] >= grid[m - 1][n - 1]) {
            return 0;
        }

        int mx = 0;
        for (auto& row : grid) {
            for (int val : row) mx = max(mx, val);
        }

        vector<int> suf_min_f(mx + 2, 2e9); 
        vector<int> min_f(mx + 1);
        vector<int> f(n + 1);

        for (int t = 0; t <= k; t++) {
            fill(min_f.begin(), min_f.end(), 2e9);
            fill(f.begin(), f.end(), 2e9);


            f[1] = (t == 0) ? 0 : f[1]; 

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int x = grid[i][j];
                    int standard_move = min(f[j], f[j + 1]) + x;
                    if (i == 0 && j == 0 && t == 0) standard_move = 0;

                    f[j + 1] = min(standard_move, suf_min_f[x]);
                    min_f[x] = min(min_f[x], f[j + 1]);
                }
            }

            vector<int> prev_suf = suf_min_f;
            suf_min_f[mx + 1] = 2e9;
            for (int i = mx; i >= 0; i--) {
                suf_min_f[i] = min(suf_min_f[i + 1], min_f[i]);
            }
            if (suf_min_f == prev_suf) break; 
        }

        return f[n];
    }
};