class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long type1 = 6;  // ABA
        long long type2 = 6;  // ABC
        
        // Build row by row from row 2 to row n
        for (int i = 1; i < n; i++) {

            long long new_type1 = (type1 * 3 + type2 * 2) % MOD;
            
            // New ABC patterns come from:
            // - Previous ABA patterns (2 ways each)
            // - Previous ABC patterns (2 ways each)
            long long new_type2 = (type1 * 2 + type2 * 2) % MOD;
            
            // Update for next iteration
            type1 = new_type1;
            type2 = new_type2;
        }
        
        // Total ways = all ABA patterns + all ABC patterns
        return (type1 + type2) % MOD;
    }
};