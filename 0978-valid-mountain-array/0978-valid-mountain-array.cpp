class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;  // A mountain array must have at least 3 elements
        
        int i = 0;
        
        // Walk up
        while (i < n - 1 && arr[i] < arr[i + 1]) {
            i++;
        }
        
        // Peak can't be first or last element
        if (i == 0 || i == n - 1) return false;
        
        // Walk down
        while (i < n - 1 && arr[i] > arr[i + 1]) {
            i++;
        }
        
        return i == n - 1;
    }
};