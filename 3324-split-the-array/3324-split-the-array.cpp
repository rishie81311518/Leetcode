class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map <int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        for(auto it: map){
            if(it.second > 2){
                return false;
            }
        }
        return true;
        
    }
};