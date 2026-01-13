class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int totalTime = 0;

        for(int i = 0; i<points.size() - 1; i++){
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i+1][0], y2 = points[i+1][1];

            while( x1 != x2 || y1 != y2){
                if (x1 != x2 && y1 != y2){
                    x1 += (x2>x1) ? 1 : -1;
                    y1 += (y2>y1) ? 1 : -1;
                }

                else if (x1 != x2){
                    x1 += (x2>x1) ? 1 : -1;
                }

                else if (y1 != y2){
                    y1 += (y2>y1) ? 1 : -1;
                }
               totalTime++;
              
            }
                

           }
           return totalTime;
        
    }
};