class Solution {
public:
    string clearDigits(string s) {
         int i =0, j=0;
        string ans = ""; 
        while (i < s.length()){
         if(!isdigit(s[i])) ans = ans + s[i];
         else ans.pop_back();
        i++;
        } 
        
        return ans;
        
    }
};