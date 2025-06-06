class Solution {
public:
   
   void solveSubsets( vector<int> &nums, vector<int> &temp, int i, vector<vector<int>> &result){

    if( i == nums.size()){
        result.push_back(temp);
        return;
    }

    temp.push_back(nums[i]);
    solveSubsets(nums, temp, i+1, result);

    temp.pop_back();
    solveSubsets(nums, temp, i+1, result);

   }


  vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solveSubsets(nums, temp, 0, result);
        return result;

};
};