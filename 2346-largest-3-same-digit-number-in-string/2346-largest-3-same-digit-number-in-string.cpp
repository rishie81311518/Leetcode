class Solution {
public:
    string largestGoodInteger(string num) {
        //brute approach we know the num only contains digits 0-9

        for (int i = 9; i >= 0; i--){
           string pattern(3, '0' + i);

           if(num.find(pattern) != string::npos){
               return pattern;
           }
        }

        return "";

        
        
    }
};