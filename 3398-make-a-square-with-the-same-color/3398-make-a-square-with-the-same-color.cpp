class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = size(grid);
       for (int i = 0; i < n - 1; i++) {
         
        for (int j = 0; j < n - 1; j++) {
          
            
            
              unordered_map<char, int> mp;
            
              mp[grid[i][j]]++;
            mp[grid[i][j+1]]++;
            mp[ grid[i+1][j]]++;
            mp[grid[i+1][j+1]]++;
             
           if(mp['W'] == 3 && mp['B'] == 1 || (mp['W'] == 1 &&  mp['B'] == 3) || (mp['W'] == 4 || mp['B'] == 4)) return true;
        }
           
    }
        return false;
    }
};