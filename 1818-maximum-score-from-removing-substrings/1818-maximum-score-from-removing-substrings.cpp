class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if (x < y) {
            swap(x, y);
            
            for (char& c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }
        
        int score = 0;
        
        string stack1;
        for (char c : s) {
            if (!stack1.empty() && stack1.back() == 'a' && c == 'b') {
                stack1.pop_back();
                score += x;       
            } else {
                stack1.push_back(c);
            }
        }
        

        string stack2;
        for (char c : stack1) {
            if (!stack2.empty() && stack2.back() == 'b' && c == 'a') {
                stack2.pop_back();
                score += y;        
            } else {
                stack2.push_back(c);
            }
        }
        
        return score;
    }
};