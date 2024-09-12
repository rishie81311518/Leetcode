#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        int startIndex = 0;
        int endIndex = k;
        
        while (endIndex < nums.size()) {
            sum = sum - nums[startIndex] + nums[endIndex];
            maxSum = std::max(maxSum, sum);
            startIndex++;
            endIndex++;
        }
        
        return static_cast<double>(maxSum) / k;
    }
};