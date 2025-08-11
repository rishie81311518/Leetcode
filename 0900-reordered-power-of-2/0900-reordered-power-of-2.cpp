class Solution {
public:
     vector<int> getDigit(long long num) {
        vector<int> count(10,0);
        while (num > 0){
            count[num % 10]++;
             num /= 10;
        }
        return count;
     }

    bool reorderedPowerOf2(int n) {
        vector<int> targetCount = getDigit(n);

        long long powerReordered = 1;
        for (int i = 0; i < 30; i++){
             if (getDigit(powerReordered) == targetCount){
                return true;
             }

             powerReordered *= 2; 
        }
        return false;
        
    }
};