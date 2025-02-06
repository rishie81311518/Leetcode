#include <iostream>
#include <string>
#include <climits>  // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int i = 0, sign = 1;

        // Step 1: Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional '+' or '-' sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to an integer
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Step 4: Check for overflow
            if (result > (LLONG_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }

        result *= sign;

        // Step 5: Clamp the result within INT_MIN and INT_MAX
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return static_cast<int>(result);
    }
};