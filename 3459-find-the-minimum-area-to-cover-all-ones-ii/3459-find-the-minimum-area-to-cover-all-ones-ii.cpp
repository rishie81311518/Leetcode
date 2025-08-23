class Solution {
    vector<vector<int>> prefix_sum;

    void computePrefixSum(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                prefix_sum[i+1][j+1] = grid[i][j] + prefix_sum[i+1][j] + prefix_sum[i][j+1] - prefix_sum[i][j];
            }
        }
    }
    int getBoxSum(int x1,int x2,int y1,int y2){
        return prefix_sum[x2+1][y2+1] - prefix_sum[x1][y2+1] - prefix_sum[x2+1][y1] + prefix_sum[x1][y1];
    }
    void findBoundingCoordinates(vector<vector<int>>& grid,int& low_x,int& high_x,int& low_y,int& high_y){
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    low_x = min(low_x,i);
                    high_x = max(high_x,i);
                    low_y = min(low_y,j);
                    high_y = max(high_y,j);
                }
            }
        }
    }
    int findMinArea(int x1,int x2,int y1,int y2,vector<vector<int>>& grid){
        int total_ones = getBoxSum(x1,x2,y1,y2);
        if(total_ones == 0) return 0;

        int min_x, max_x, min_y, max_y;

        // Binary search to find optimal bounding box
        // Find min_x
        min_x = x2;
        int low = x1, high = x2, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(getBoxSum(x1,mid,y1,y2) > 0){
                min_x = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        // Find max_x
        max_x = x1;
        low = x1, high = x2;
        while(low <= high){
            mid = low + (high-low)/2;
            if(getBoxSum(mid,x2,y1,y2) > 0){
                max_x = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        // Find min_y
        min_y = y2;
        low = y1, high = y2;
        while(low <= high){
            mid = low + (high-low)/2;
            if(getBoxSum(x1,x2,y1,mid) > 0){
                min_y = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        // Find max_y
        max_y = y1;
        low = y1, high = y2;
        while(low <= high){
            mid = low + (high-low)/2;
            if(getBoxSum(x1,x2,mid,y2) > 0){
                max_y = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        prefix_sum.assign(m+1,vector<int>(n+1));
        computePrefixSum(grid);

        int low_x = INT_MAX, high_x = -1;
        int low_y = INT_MAX, high_y = -1;
        findBoundingCoordinates(grid,low_x,high_x,low_y,high_y);

        int lowest_area = INT_MAX;
        int area;
        for(int i=low_x;i<high_x;++i){
            for(int j=low_y;j<high_y;++j){
                for(int count=1;count<=4;++count){
                    switch(count){
                        case 1://Up
                            area = findMinArea(low_x,i,low_y,j,grid) +
                                   findMinArea(low_x,i,j+1,high_y,grid) +
                                   findMinArea(i+1,high_x,low_y,high_y,grid);
                            break;
                        case 2://Right
                            area = findMinArea(low_x,high_x,low_y,j,grid) + 
                                   findMinArea(low_x,i,j+1,high_y,grid) +
                                   findMinArea(i+1,high_x,j+1,high_y,grid);
                            break;
                        case 3://Down
                            area = findMinArea(low_x,i,low_y,high_y,grid) +
                                   findMinArea(i+1,high_x,low_y,j,grid) +
                                   findMinArea(i+1,high_x,j+1,high_y,grid);
                            break;
                        case 4://Left
                            area = findMinArea(low_x,i,low_y,j,grid) +
                                   findMinArea(i+1,high_x,low_y,j,grid) +
                                   findMinArea(low_x,high_x,j+1,high_y,grid);
                            break;
                    }
                    lowest_area = min(lowest_area,area);
                }
            }
        }
        //Case-5: Horizontal Slicing
        for(int i=low_x;i<high_x-1;++i){
            for(int j=i+1;j<high_x;++j){
                lowest_area = min(lowest_area, findMinArea(low_x,i,low_y,high_y,grid) +
                                               findMinArea(i+1,j,low_y,high_y,grid) +
                                               findMinArea(j+1,high_x,low_y,high_y,grid));
            }
        }
        //Case-6: Vertical Slicing
        for(int i=low_y;i<high_y-1;++i){
            for(int j=i+1;j<high_y;++j){
                lowest_area = min(lowest_area, findMinArea(low_x,high_x,low_y,i,grid) +
                                               findMinArea(low_x,high_x,i+1,j,grid) +
                                               findMinArea(low_x,high_x,j+1,high_y,grid));
            }
        }
        return lowest_area;
    }
};