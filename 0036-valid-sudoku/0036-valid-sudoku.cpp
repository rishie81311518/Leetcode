class Solution {
public:
    bool isvalidrow(vector<vector<char>>& board,int r,int c){
        for(int j=0;j<9;j++){
            if(j!=c && board[r][j]==board[r][c]){
                return false;
            }
        }
        return true;
    }
    bool isvalidcol(vector<vector<char>>& board,int r,int c){
        for(int i=0;i<9;i++){
            if(i!=r && board[i][c]==board[r][c]){
                return false;
            }
        }
        return true;
    }
    bool isvalidgrid(vector<vector<char>>& board,int r,int c){
        int str = r - (r%3), stc = c - (c%3);
        for(int i=str;i<str+3;i++){
            for(int j=stc;j<stc+3;j++){
                if(board[i][j]==board[r][c]){
                    if(i!=r || j!=c){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]>='0' && board[i][j]<='9'){
                    if(!(isvalidrow(board,i,j) && isvalidcol(board,i,j) && isvalidgrid(board,i,j))){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};