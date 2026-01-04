class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int divisorCount = 0;
            int divisorSum = 0;
        
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    divisorCount++;
                    divisorSum += i;
                    
                    if (i * i != num) {
                        divisorCount++;
                        divisorSum += num / i;
                    }
                }
                
                if (divisorCount > 4) {
                    break;
                }
            }
            
            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }
        
        return totalSum;
    }
};