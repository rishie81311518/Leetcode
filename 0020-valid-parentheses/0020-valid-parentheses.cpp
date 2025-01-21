class Solution {
public:
    bool isValid(string s) {
       unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    // Stack to keep track of open brackets
    stack<char> stk;

    // Iterate through the string
    for (char ch : s) {
        // If the character is a closing bracket
        if (brackets.find(ch) != brackets.end()) {
            // Check if the stack is non-empty and matches the expected opening bracket
            if (!stk.empty() && stk.top() == brackets[ch]) {
                stk.pop(); // Remove the matched opening bracket from the stack
            } else {
                return false; // Mismatched or unbalanced closing bracket
            }
        } else {
            // If it's an opening bracket, push it onto the stack
            stk.push(ch);
        }
    }

    // If the stack is empty, all brackets are balanced; otherwise, it's invalid
    return stk.empty();

        
    }
};