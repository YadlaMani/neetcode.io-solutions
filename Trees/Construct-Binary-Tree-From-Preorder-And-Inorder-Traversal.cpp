/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>&preorder,int preSt,int preEnd,vector<int>&inorder,int inSt,int inEnd,unordered_map<int, int>& mp){
        if(preSt>preEnd || inSt>inEnd){//if we excceed size return null
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preSt]);//preorder first ele will be root
        int idx=mp[root->val];//search the index of that root element
        int size=idx - inSt;//no.of left sub tree elements 
        root->left=helper(preorder,preSt+1,preSt+size,inorder,inSt,idx-1,mp);//Preorder[initial+1:intial+size] Inorder[initial:idx-1]
        root->right=helper(preorder,preSt+size+1,preEnd,inorder,idx+1,inEnd,mp);//Preorder[initial+size+1:End] Inorder[idx+1:End]
        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        //inorder map for index of a value
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }//helper function
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};
