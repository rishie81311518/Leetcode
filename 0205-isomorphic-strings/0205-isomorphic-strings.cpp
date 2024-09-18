class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        // Two maps to store mappings from s to t and t to s
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // If there's already a mapping from s to t, check if it matches the current character in t
            if(mapST.count(c1)) {
                if(mapST[c1] != c2) {
                    return false;
                }
            }
            // If there's already a mapping from t to s, check if it matches the current character in s
            else if(mapTS.count(c2)) {
                if(mapTS[c2] != c1) {
                    return false;
                }
            }
            // If no mapping exists, create a new mapping
            else {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
        }

        return true;
    }
};
