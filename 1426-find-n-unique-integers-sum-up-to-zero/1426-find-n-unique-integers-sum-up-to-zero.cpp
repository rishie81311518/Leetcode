class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int temp = n/2;
        int start = 0;
        int end = n-1;
        while (start <= end) {
            result[start] = temp;
            result[end] = -temp;
           temp--;
           start++;
           end--;
        }
        return result;
    }
};