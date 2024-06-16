class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Look the table like a binary tree and top most right element as node and you will get this approach
       int n=matrix.size();
        int m=matrix[0].size();
        int row=0,col=m-1;//root node
        while(row<n&&col>-1){
            int val=matrix[row][col];
            if(target==val){
                return true;
            }
            else{
                if(target>val){//if value not found and target is larger than val traverse right side
                    row++;
                }
                else{//else traverse left side of the tree
                    col--;
                }
            }
        }
        //for the first example start from 7 you will get the approach
        return false;
    }
};
