class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[i] = i + (nums[i] % n);
                if (result[i] >= n) result[i] -= n;
                result[i] = nums[result[i]];
            } else if (nums[i] < 0) {
                result[i] = i - ((-nums[i]) % n);
                if (result[i] < 0) result[i] += n;
                result[i] = nums[result[i]];
            } else {
                result[i] = nums[i];
            }
        }
        
        return result;
    }
};