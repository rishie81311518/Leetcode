#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        int count = 0; // Tracks consecutive odd numbers
        for (int num : arr) {
            if (num % 2 != 0) { // If number is odd
                count++;
                if (count == 3) { // Found three consecutive odds
                    return true;
                }
            } else { // If number is even, reset count
                count = 0;
            }
        }
        return false;
    }
};