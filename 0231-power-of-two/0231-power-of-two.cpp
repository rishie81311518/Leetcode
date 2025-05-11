class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Handle non-positive numbers (not powers of 2)
        if (n <= 0) {
            return false;
        }
        // A number that is a power of 2 has exactly one bit set.
        // Using bitwise AND: n & (n-1) clears the least significant set bit.
        // If n is a power of 2, n & (n-1) will be 0.
        return (n & (n - 1)) == 0;
    }
};