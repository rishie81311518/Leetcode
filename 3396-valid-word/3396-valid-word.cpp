class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = word.size();
        if (n < 3) return false;
        
        bool hasDigit = false, hasUpper = false, hasLower = false, hasVowel = false, hasConsonant = false;
        
        for (char c : word) {
            if (!isalnum(c)) return false;
            if (isdigit(c)) hasDigit = true;
            else if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            
            if (vowels.count(c)) hasVowel = true;
            else if (isalpha(c)) hasConsonant = true;
        }
        
        return (hasDigit || hasUpper || hasLower) && hasConsonant && hasVowel;
    }
};