class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for( int i =0; i < nums.size(); i++) {
              int digit = 0;
          while(nums[i] > 0){
            digit++;
            nums[i] = nums[i]/10;
          }
           if(digit % 2 == 0){
             ans++;
           }

        }
        return ans;
        
    }
};