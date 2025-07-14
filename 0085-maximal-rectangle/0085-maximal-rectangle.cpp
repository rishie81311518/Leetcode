#include <vector>
#include <string>
#include <algorithm>
#include <stack>

class Solution {
public:
    int largestRectangleArea(const std::vector<int>& heights) {
        std::stack<int> s;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) { 
            int h = (i == n) ? 0 : heights[i]; 

            while (!s.empty() && heights[s.top()] >= h) {
                int height_val = heights[s.top()];
                s.pop();

                int width = s.empty() ? i : (i - s.top() - 1);
                max_area = std::max(max_area, height_val * width);
            }
            s.push(i);
        }
        return max_area;
    }

    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_rectangle_area = 0;
        std::vector<int> heights(cols, 0);

        for (int i = 0; i < rows; ++i) {
         
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0; 
                }
            }


            max_rectangle_area = std::max(max_rectangle_area, largestRectangleArea(heights));
        }

        return max_rectangle_area;
    }
};