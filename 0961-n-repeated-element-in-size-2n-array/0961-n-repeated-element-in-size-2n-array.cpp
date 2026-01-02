class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
     int n = nums.size();

     for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 3 && i+j<n; j++){
            if(nums[i] == nums[i+j])
            return nums[i];
        }
     }
     return -1;

        
    }
};