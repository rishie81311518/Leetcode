class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int maxKeep = 1;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            while (left < right && nums[right] > (long long)k * nums[left]) {
                left++;
            }
            maxKeep = max(maxKeep, right - left + 1);
        }
        
        return n - maxKeep;
    }
};