class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        
        int cost1 = nums[0];
        
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i+1]);
        }
        
        int minCost = INT_MAX;
        
        for (int i = 1; i < n - 1; i++) {
            int cost2 = nums[i];
            int cost3 = suffixMin[i+1];
            
            minCost = min(minCost, cost1 + cost2 + cost3);
        }
        
        return minCost;
    }
};