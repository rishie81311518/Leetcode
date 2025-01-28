class Solution {
public:
    bool checkIfPangram(string s) {
       vector<bool> alpha(26,0);

       for (int i =0; i<s.size(); i++){
         alpha[s[i] - 'a'] = 1;
       }

       for(int i = 0; i<26; i++){
        if (alpha[i] == 0)
        return 0;
       }

       return 1;
    }
};
