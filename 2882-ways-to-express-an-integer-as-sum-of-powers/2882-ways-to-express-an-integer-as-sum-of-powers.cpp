class Solution {
public:
    int numberOfWays(int n, int x) {
        static const int mod = 1e9 + 7;

        vector<long long> dp(n+1, 0);
        dp[0] = 1;

        int base_number = 1;

        while(true){
            long long power = (long long)pow(base_number,x);

            if (power > n){
                break;
            }

            for (int currentSum = n; currentSum >= power; currentSum--){
                dp[currentSum] = (dp[currentSum] + dp[currentSum - power]) % mod;
            }

            base_number++;


        }
       return dp[n];
        
    }
};