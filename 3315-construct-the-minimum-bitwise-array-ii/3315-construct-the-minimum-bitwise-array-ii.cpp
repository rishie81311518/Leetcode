class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int target = nums[i];
            int result = -1;
            
            for(int bit = 0; bit < 31; bit++) {
                if((target >> bit) & 1) {
                    int candidate = target ^ (1 << bit);
                    if((candidate | (candidate + 1)) == target) {
                        if(result == -1 || candidate < result) {
                            result = candidate;
                        }
                    }
                }
            }
            
            ans[i] = result;
        }
        
        return ans;
    }
};