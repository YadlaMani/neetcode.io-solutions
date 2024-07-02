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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){//null case
            return {};
        }
        queue<TreeNode*>q;//maintain a queue for level order traversal
        q.push(root);
        vector<vector<int>>ans;
        ans.push_back({});//first row
        int i=0;//first row
        int sum=0;//no.of elements in each row
        int level=1;//current row elements
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            level--;//decrease the count of the vals in current row
            ans[i].push_back(temp->val);
            //inserting left and right child
            if(temp->left!=NULL){
                q.push(temp->left);
                sum++;
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                sum++;
            }
            if(level==0){//if done traversing the current row elements
                level=sum;//assign next row elements
                sum=0;//make sum 0 for next row 
                if(level!=0){
                    i++;//increase level
                    ans.push_back({});

                }
                
            }
            
        }
        return ans;
    }
};
