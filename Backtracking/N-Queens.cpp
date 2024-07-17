class Solution {
public:
//backtracking solution
    bool isSafe(int x,int y,vector<string>&s){//function to check the placement of the queen is safe or not 

        int row=x;
        int col=y;
        //checking queen in that row  
        while(col>=0){
            if(s[row][col]=='Q') return false;
            col--;
        }
        //checking the negative diagonal
        col=y;
        while(row>=0 && col>=0){
            if(s[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=x;
        col=y;
        //checking the positive diagonal
        while(row<s.size() && col>=0){
            if(s[row][col]=='Q') return false;
            row++;
            col--;
        }
        //is position is safe return the true
        return true;

        
    }
    void solve(int col,vector<string>s,int n,vector<vector<string>>&ans){
        if(col==n){//when we reach the last column without any conflicts the combination is correct we push the vector into the ans
            ans.push_back(s);
            return;
        }
        for(int i=0;i<n;i++){
            //checking if the col is safe with different row combinations
            if(isSafe(i,col,s)){
                //if safe we place the queen there
                s[i][col]='Q';
                //and move onto the next column to get the furthur placement
                solve(col+1,s,n,ans);
                //remove that queen postion for other recursion tree
                s[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //ans vector to push the array
        vector<vector<string>>ans;
        vector<string>s(n,string(n,'.'));//creating a row with n '...' with n rows
        solve(0,s,n,ans);//calling the solve function
        return ans;

    }
};
