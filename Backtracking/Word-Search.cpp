class Solution {
public:
    bool bfs(vector<vector<char>>&board,string word,int i,int j,int size){
        //if we get whole word return true
        if(size==word.size()){
            return true;

        }
        //if we reach out of bounds or the current board char is not the word character we need return false
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[size]){
            return false;
        }
        //store the currnet board character if it matches
        char temp = board[i][j];
        //make it some random character so that we don't consider it again during traversal
        board[i][j] = '*';
        //check for the next word character similarly
        bool valid=bfs(board,word,i+1,j,size+1) || bfs(board,word,i-1,j,size+1) || bfs(board,word,i,j+1,size+1) || bfs(board,word,i,j-1,size+1);//bfs in four directions
        //after traversal make the board current to it's default value for that traversals
        board[i][j]=temp;
        
        return valid;


    }
    bool exist(vector<vector<char>>& board, string word) {
        //traverse the board
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //when we encounter first element on the board check for the word in the board 
                if(board[i][j]==word[0] && bfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
