class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int allXor = 0;
        for (int i =0; i<= nums.size();i++){
            allXor = allXor ^ i;
        }

        for(int num : nums){
            allXor = allXor ^ num;
        }
        return allXor;
    }
};