class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        vector<pair<int, int>> events;

        for (const auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            totalArea += (double)l * l;
            events.push_back({y, l}); 
            events.push_back({y + l, -l});
        }

        
        sort(events.begin(), events.end());

        double targetArea = totalArea / 2.0;
        double currentArea = 0;
        long long currentWidth = 0;
        int prevY = events[0].first;

        for (const auto& event : events) {
            int currY = event.first;
            long long heightDiff = currY - prevY;
            double areaIncrease = (double)currentWidth * heightDiff;

            if (currentArea + areaIncrease >= targetArea) {
                double neededArea = targetArea - currentArea;
                return prevY + (neededArea / currentWidth);
            }

            currentArea += areaIncrease;
            currentWidth += event.second;
            prevY = currY;
        }

        return 0.0; 
    }
};