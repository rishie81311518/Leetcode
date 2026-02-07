class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int deletions = 0;
        int bCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                bCount++;
            } else {
                deletions = min(deletions + 1, bCount);
            }
        }
        
        return deletions;
    }
};