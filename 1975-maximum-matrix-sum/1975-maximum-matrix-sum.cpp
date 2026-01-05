class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absSum = 0;
        int minAbs = INT_MAX;
        int oddNeg = 0;

        for (const auto& row : matrix) {
            for (int num : row) {
                absSum += abs(num);
                minAbs = min(minAbs, abs(num));
                if (num < 0) {
                    oddNeg ^= 1;
                }
            }
        }
        
        return absSum - (oddNeg * (long long)minAbs * 2);
    }
};