class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10); // Create a vector to store words by position
        string temp = "";       // Temporary string to store a word
        int index = 0;          // Index for iteration

        // Parse the input string
        while (index < s.size()) {
            if (s[index] == ' ') { // If a space is found
                int pos = temp[temp.size() - 1] - '0'; // Get the position (last character of temp)
                temp.pop_back();                      // Remove the position from the word
                ans[pos] = temp;                      // Store the word in the vector
                temp.clear();                         // Clear temp for the next word
            } else {
                temp += s[index]; // Add the character to temp
            }
            index++;
        }

        // Handle the last word (if there are no trailing spaces)
        if (!temp.empty()) {
            int pos = temp[temp.size() - 1] - '0';
            temp.pop_back();
            ans[pos] = temp;
        }

        // Construct the sorted sentence
        string result = "";
        for (int i = 1; i < ans.size(); i++) {
            if (!ans[i].empty()) { // Ignore empty positions
                result += ans[i] + " ";
            }
        }

        if (!result.empty()) {
            result.pop_back(); // Remove the trailing space
        }

        return result;
    }
};
