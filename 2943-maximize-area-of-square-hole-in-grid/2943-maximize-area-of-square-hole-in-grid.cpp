class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxHConsecutive = findMaxConsecutive(hBars);
        int maxVConsecutive = findMaxConsecutive(vBars);
        
        int maxHGap = maxHConsecutive + 1;
        int maxVGap = maxVConsecutive + 1;
        
        int side = min(maxHGap, maxVGap);
        return side * side;
    }
    
private:
    int findMaxConsecutive(vector<int>& bars) {
        if (bars.empty()) return 0;
        
        sort(bars.begin(), bars.end());
        
        int maxConsecutive = 1;
        int currentConsecutive = 1;
        
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) {
                currentConsecutive++;
                maxConsecutive = max(maxConsecutive, currentConsecutive);
            } else {
                currentConsecutive = 1;
            }
        }
        
        return maxConsecutive;
    }
};