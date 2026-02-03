class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        int i = 0;
        
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
        }
        
        if (i == 0 || i == n - 1) return false;
        
        int p = i;
        
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            i++;
        }
        
        if (i == p || i == n - 1) return false;
        
        int q = i;
        
        while (i < n - 1) {
            if (nums[i] >= nums[i + 1]) return false;
            i++;
        }
        
        return true;
    }
};