class Solution {
public:
    string reverseWords(string s) {
        stack<string> words; 
    stringstream ss(s);  
    string word, result = "";

    
    while (ss >> word) {
        words.push(word);
    }

    
    while (!words.empty()) {
        result += words.top(); 
        words.pop();
        if (!words.empty()) {
            result += " "; 
        }
    }

    return result;
        
    }
};