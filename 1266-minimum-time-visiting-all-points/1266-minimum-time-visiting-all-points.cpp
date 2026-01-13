class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //Better

        int totalTime = 0;

        for(int i = 0; i<points.size() - 1; i++){
           int x1 = points[i][0], y1 = points[i][1];
           int x2 = points[i+1][0], y2 = points[i+1][1];


            int dx = abs(x2-x1);
            int dy = abs(y2-y1);

            int diagonalMoves = min(dx,dy);
            int straightMoves = abs(dx-dy);

            totalTime += diagonalMoves + straightMoves; 
        }

        return totalTime;
    }
         
};