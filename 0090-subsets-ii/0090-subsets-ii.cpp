class Solution {
public:
    void findSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Always add the current subset

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]); // Choose the current element
            findSubsets(i + 1, nums, current, result); // Recurse
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        findSubsets(0, nums, current, result);
        return result;
    }
};