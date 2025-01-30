#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        int carry = 0;
        std::string result = "";
        
        while (p1 >= 0 || p2 >= 0 || carry > 0) {
            int digit1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int digit2 = p2 >= 0 ? num2[p2] - '0' : 0;
            
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
            
            p1--;
            p2--;
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
