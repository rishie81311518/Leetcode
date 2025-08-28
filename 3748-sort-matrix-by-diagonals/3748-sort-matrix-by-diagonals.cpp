class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++){
            vector<int> vec;
            for(int j=0;i+j<n;j++){
                vec.push_back(grid[i+j][j]);
            }
            sort(vec.rbegin(),vec.rend());
            for(int j=0;i+j<n;j++){
                grid[i+j][j] = vec[j];
            }
        }
        for(int j=1;j<n;j++){
            vector<int> vec;
            for(int i=0;i+j<n;i++){
                vec.push_back(grid[i][j+i]);
            }
            sort(vec.begin(),vec.end());
            for(int i=0;i+j<n;i++){
                grid[i][j+i] = vec[i];
            }
        }
        return grid;
    }
};