class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int> freq;
        

        for (int i : nums) freq[i]++;

        int ans = 0;
         for(auto p: freq){
            if(p.second == 2){
                ans = ans^p.first;
            }
         }
         return ans;
         
    }
};