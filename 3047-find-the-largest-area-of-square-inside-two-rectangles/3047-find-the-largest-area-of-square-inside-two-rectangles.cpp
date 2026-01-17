class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long x1_i = bottomLeft[i][0];
                long long y1_i = bottomLeft[i][1];
                long long x2_i = topRight[i][0];
                long long y2_i = topRight[i][1];
                
                long long x1_j = bottomLeft[j][0];
                long long y1_j = bottomLeft[j][1];
                long long x2_j = topRight[j][0];
                long long y2_j = topRight[j][1];
                
                long long x1_inter = max(x1_i, x1_j);
                long long y1_inter = max(y1_i, y1_j);
                long long x2_inter = min(x2_i, x2_j);
                long long y2_inter = min(y2_i, y2_j);
                
                if (x1_inter < x2_inter && y1_inter < y2_inter) {
                    long long width = x2_inter - x1_inter;
                    long long height = y2_inter - y1_inter;
                    long long sideLength = min(width, height);
                    long long area = sideLength * sideLength;
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};