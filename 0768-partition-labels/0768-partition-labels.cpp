class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26,0);
        vector<int> result;

        for(int i = 0; i<s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }

        int lastMax = 0, partitionStart  = 0;
        for (int i = 0; i < s.size(); i++) {
            lastMax = max(lastMax, lastIndex[s[i] - 'a']); 
            if (i == lastMax) {
                result.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return result;
    }
};