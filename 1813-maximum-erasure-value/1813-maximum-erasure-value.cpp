class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen; 
    int max_sum = 0;
    int curr_sum = 0;
    int left = 0; 
    
    for (int right = 0; right < nums.size(); ++right) {
        while (seen.find(nums[right]) != seen.end()) {
            seen.erase(nums[left]);
            curr_sum -= nums[left];
            ++left;
        }
       
        seen.insert(nums[right]);
        curr_sum += nums[right];
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
    }
};