class Solution {
private:
    bool isvalid(int row , int col , vector<vector<char>>& board, int c){
        //Checking row;
        for(int i = 0 ; i <9 ; i++){
            if(board[i][col] == c){
                return false;
            }
            
            //checking columns; 
            if(board[row][i] == c)
                return false;
            
            //checking the 3*3 grid
            if(board[3*(row/3) +i /3][3*(col/3)+i % 3] == c){
                return false;
            }

        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isvalid(i,j,board,c)){
                            board[i][j] = c;

                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                     return false;   
                }

            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};