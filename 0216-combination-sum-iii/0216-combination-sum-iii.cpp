class Solution {
public:
     void findCombination(int start, int k, int n, vector<vector<int>> &result, vector<int> &ds){
        if (ds.size() == k){
            if (n == 0)
            result.push_back(ds);
            return;
        }

        for (int i = start; i<=9; ++i ){
            // avoid storing duplicate
            if ( i > n) break;
            ds.push_back(i);
            findCombination(i+1, k, n-i, result,ds);
            ds.pop_back();
        }


     }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ds;
        findCombination(1,k,n,result,ds);
        return result;

    }
};