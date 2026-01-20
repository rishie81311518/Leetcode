class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }
            
            int x = nums[i];
            int mask = 1;
            
            while ((x & mask) != 0) {
                mask <<= 1;
            }
            
            ans[i] = nums[i] ^ (mask >> 1);
        }
        
        return ans;
    }
};