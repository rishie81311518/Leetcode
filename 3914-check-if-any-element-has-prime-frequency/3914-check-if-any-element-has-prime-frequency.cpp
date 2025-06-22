
 bool isFrequency(int n){
        if( n <= 1){
            return false;
        }
        if (n ==2)
            return true;
        if ( n % 2 == 0)
            return false;

        for (int i = 3; i*i <=n ; i +=2){
            if ( n % 3 == 0 )
                return false;

        }
     return true;
    }

class Solution {
    
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> frequencies;

        for (int num : nums ){
            frequencies[num]++;
        }

        for (const auto& pair: frequencies){
            int frequency = pair.second;
            if (isFrequency(frequency)){
                return true;
            }

            
        }
        return false;
    }
};