class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        if(n<3) return false;
        
        for(int p = 1; p<n; p++){
            for(int q = p+1; q<n-1; q++){
                bool firstIncreasing = true;
                for(int i =0; i<p; i++){
                if (nums[i] >= nums[i+1]){
                      firstIncreasing = false;
                      break;
                }
                }

                if (!firstIncreasing) continue;

                bool middleDecreasing = true;

                for(int i = p; i<q;i++){
                    if(nums[i] <= nums[i+1]){
                    middleDecreasing = false;
                    break;
                }
                }

                if(!middleDecreasing) continue;

                bool lastIncreasing = true;

                for(int i = q; i<n-1; i++){
                    if(nums[i] >= nums[i+1]){
                    lastIncreasing = false;
                    break;
                }
                }

                if (lastIncreasing) return true;

            }
        }

        return false;
    }
};