class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minDiff = INT_MAX;
        vector<vector<int>> result;

        for(int i = 0; i < n-1; i++){
            int diff = arr[i+1] - arr[i];

            if (diff < minDiff){
                minDiff = diff;
                result.clear();
                result.push_back({arr[i], arr[i+1]});
            }

            else if(diff == minDiff){
                result.push_back({arr[i], arr[i+1]});
            }
        }

       return result;
        
    }
};