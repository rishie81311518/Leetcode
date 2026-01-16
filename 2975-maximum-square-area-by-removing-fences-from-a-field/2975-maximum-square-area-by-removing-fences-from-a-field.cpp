class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }
        
        int maxSquareSide = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int vGap = vFences[j] - vFences[i];
                if (hGaps.count(vGap)) {
                    maxSquareSide = max(maxSquareSide, vGap);
                }
            }
        }

        if (maxSquareSide == -1) return -1;
        
        long long area = (long long)maxSquareSide * maxSquareSide;
        return area % MOD;
    }
};