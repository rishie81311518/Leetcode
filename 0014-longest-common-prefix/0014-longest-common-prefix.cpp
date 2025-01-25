class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: if the input vector is empty, return an empty string
        if (strs.empty()) return "";

        // Start with the first string as the prefix
        string prefix = strs[0];

        // Iterate through the rest of the strings in the vector
        for (int i = 1; i < strs.size(); ++i) {
            // Compare the prefix with the current string
            while (strs[i].find(prefix) != 0) {
                // If the prefix is not found at the start of the current string, reduce it
                prefix = prefix.substr(0, prefix.size() - 1);

                // If the prefix becomes empty, return an empty string
                if (prefix.empty()) return "";
            }
        }

        // Return the final common prefix
        return prefix;
    }
};
