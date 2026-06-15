class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // row checking
    for(int i = 0; i<9; i++){

    unordered_set<char> seen;

    for(int j = 0; j<9; j++){

        if(board[i][j]== '.'){
            continue;
        }
        if(seen.find(board[i][j]) != seen.end()){
            return false;
        }
        seen.insert(board[i][j]);
}
}    
   

    // column checking
    for(int j =0; j<9; j++){
        unordered_set<char> seen;
        for(int i=0; i<9; i++){
            if(board[i][j] == '.'){
                continue;
            }

            if(seen.find(board[i][j]) != seen.end()){
                return false;
            }
            seen.insert(board[i][j]);
        }
    }

    
    // 3*3 box checking
    for(int row = 0; row<9; row+=3){
        for(int col=0; col<9; col+=3){

            unordered_set<char> seen;

            for(int i = row; i<row+3; i++){
                for(int j = col; j<col+3; j++){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    if(seen.find(board[i][j]) != seen.end()){
                        return false;
                    }
                    seen.insert(board[i][j]);
                }
            }   
        }

    }
    return true;
 }
};

