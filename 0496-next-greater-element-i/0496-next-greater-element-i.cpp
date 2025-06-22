class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
        vector<int> nge(n, -1); 
        stack<int> s; 

      
        for (int i = n - 1; i >= 0; i--) {
           
            while (!s.empty() && nums2[s.top()] <= nums2[i]) {
                s.pop();
            }
            
            if (!s.empty()) {
                nge[i] = nums2[s.top()];
            }
            
            s.push(i);
        }

        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> ngeMap;
        for (int i = 0; i < n; i++) {
            ngeMap[nums2[i]] = nge[i];
        }
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = ngeMap[nums1[i]];
        }

        return result;
    }
};