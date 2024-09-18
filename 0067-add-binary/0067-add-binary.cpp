class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        // Loop until both strings are processed or there is no carry left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with the carry from the previous step
            
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int and add
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int and add
                j--;
            }
            
            carry = sum / 2;  // Calculate carry for the next position
            result += (sum % 2) + '0';  // Add the current digit (0 or 1) to the result
        }
        
        // The result is built in reverse order, so we need to reverse it before returning
        reverse(result.begin(), result.end());
        
        return result;
    }
};
