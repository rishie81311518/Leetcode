class Solution {
public:
    string largestGoodInteger(string num) {
        //better approach

        int maxDigit = -1;
        for (int i = 0; i <= num.size() - 3; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                   maxDigit = max(maxDigit, num[i] - '0');
            }
        }
        if (maxDigit == -1) return "";
        return string (3, '0' + maxDigit);

        
        
    }
};