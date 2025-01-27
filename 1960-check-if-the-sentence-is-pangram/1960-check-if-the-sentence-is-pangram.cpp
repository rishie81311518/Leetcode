class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> seen(26, false); // To track presence of each alphabet
        int count = 0; // Count of unique alphabets

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') { // Ensure it's a lowercase letter
                int index = ch - 'a';
                if (!seen[index]) { // If this alphabet hasn't been seen before
                    seen[index] = true;
                    count++;
                    if (count == 26) return true; // Early exit if all alphabets are found
                }
            }
        }

        return false; // If less than 26 unique letters are found
    }
};
