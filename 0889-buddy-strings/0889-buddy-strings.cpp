class Solution {
public:
    bool buddyStrings(string s, string goal) { 
        if (s.size() != goal.size()) 
            return false;

        // Case 1: s and goal are the same, check for duplicate characters
        if (s == goal) {
            unordered_set<char> charSet(s.begin(), s.end());
            return charSet.size() < s.size();  // True if there are duplicate characters
        }

        // Case 2: s and goal are different, find the two mismatched indices
        int first = -1, second = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false;  // More than two mismatches
                }
            }
        }

        // Ensure there are exactly two mismatches and they can be swapped to match
        if (first == -1 || second == -1) return false;

        swap(s[first], s[second]);
        return s == goal;
    }
};
