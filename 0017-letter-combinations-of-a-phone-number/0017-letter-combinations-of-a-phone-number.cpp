class Solution {
public:
     
     void allPossibleWords(string &digits, int index, vector<string> &res, vector<string> &padMap, string &prefix) {
        // if index matches with the combination of the prefix then add it to result
        if (index == digits.size()){
            res.push_back(prefix);
            return;
        }

        int digit = digits[index] - '0';

        if(digit < 2 || digit > 9) {
            allPossibleWords(digits, index + 1, res, padMap, prefix);
            return;
        }

        for(char ch: padMap[digit]){
            prefix.push_back(ch);
            allPossibleWords(digits, index +1, res, padMap, prefix);
            prefix.pop_back();
        }
     }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        vector<string> padMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string prefix = "";
        allPossibleWords(digits, 0, res, padMap, prefix);
        return res;
    }
};