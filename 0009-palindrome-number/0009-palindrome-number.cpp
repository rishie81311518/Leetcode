class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers and numbers ending with 0
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        
        // Only need to revert half of the number
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // When length is odd, we need to get rid of the middle digit
        // For example, when input is 12321, x = 12, revertedNumber = 123
        return x == revertedNumber || x == revertedNumber / 10;
    }
};