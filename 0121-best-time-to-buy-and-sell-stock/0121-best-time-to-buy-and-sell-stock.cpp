class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maximumProfit = 0;
        int n = prices.size();
        for(int i = 1 ; i<n; i++){
            int cost = prices[i] - mini;
             maximumProfit = max(maximumProfit, cost);
             mini = min(mini, prices[i]);
        }
        return maximumProfit;
        
    }
};