class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        
        if(target >= letters[right]) {
            return letters[0];
        }

        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return letters[left];
    }
};