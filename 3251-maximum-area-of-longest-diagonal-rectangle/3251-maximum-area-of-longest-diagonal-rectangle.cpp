class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagonal = 0;
        int maxArea = 0;

        for (const auto& rect : dimensions) {
              int length = rect[0];
              int width = rect[1];

              long long diagonal = (long long)length * length + (long long) width* width;
              int area = length * width;

              if (diagonal > maxDiagonal){
                    maxDiagonal = diagonal;
                    maxArea = area;
                
         }
         else if (diagonal >= maxDiagonal && area > maxArea) {
                  maxArea = area;
         }
         }
         return maxArea;
    }
};