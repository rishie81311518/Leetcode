class Solution {
public:
    string frequencySort(string s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Create a vector of pairs (frequency, character)
        vector<pair<int, char>> charFreq;
        for (auto& p : freq) {
            charFreq.push_back({p.second, p.first});
        }
        
        // Sort the vector in descending order of frequency
        sort(charFreq.begin(), charFreq.end(), greater<pair<int, char>>());
        
        // Build the result string
        string result;
        for (auto& p : charFreq) {
            result.append(p.first, p.second);
        }
        
        return result;
    }
};
