class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         unordered_set<char> rows[9];//Keeping the track row vise
        unordered_set<char> cols[9];//Keeping the track column vise
        unordered_set<char> boxes[9];//Keeping the track box vise
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j] == '.') {
                    continue;
                }

          
               
                char curr=board[i][j];
                int boxIndex = (i / 3) * 3 + (j / 3);
                //if there exists the element already in any other set return false
                if(rows[i].count(curr)||cols[j].count(curr)||boxes[boxIndex].count(curr)){
                    return false;
                }
                rows[i].insert(curr);//adding the element in row set
                cols[j].insert(curr);//adding the element in col set
                boxes[boxIndex].insert(curr);//adding the element in box set
            }
        }
        return true;
    }
};
