class Solution {
public:
    bool isPowerOfThree(int n) {
    const int max_Power = 1162261467;
    return n > 0 && (max_Power % n == 0);
    }
    
};