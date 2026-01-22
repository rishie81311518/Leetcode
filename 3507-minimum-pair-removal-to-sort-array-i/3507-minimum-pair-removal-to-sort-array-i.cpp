class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        int operations = 0;
        
        while (true) {
            bool sorted = true;
            int minSum = INT_MAX;
            int minIdx = -1;
            
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) sorted = false;
                
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }
            
            if (sorted) break;
            
            nums[minIdx] += nums[minIdx + 1];
            nums.erase(nums.begin() + minIdx + 1);
            operations++;
        }
        
        return operations;
    }
};