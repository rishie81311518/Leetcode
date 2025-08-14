class Solution {
public:
    string largestGoodInteger(string num) {
        //brute force approach iterating through string

        string maxNum = "";
        for(int i = 0; i <= num.size() - 3; i++){
            string subString = num.substr(i,3);
            if (subString[0] == subString[1] && subString[1] == subString[2]){
                if (subString > maxNum)
                      maxNum = subString;
            }
        }
        return maxNum;
        
    }
};