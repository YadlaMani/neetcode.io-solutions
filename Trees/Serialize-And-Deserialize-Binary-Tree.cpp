/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
    TreeNode* deserializeHelper(queue<string>& nodes) {
        //base condition
        if (nodes.empty()) {
            return NULL;
        }
        //store the val of the front
        string val = nodes.front();
        nodes.pop();
        //if the node is null return NULL
        if (val == "null") {
            return NULL;
        }
        //otherwise store the root and and get the left and right sub-tree
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return string("null");
        }
        //serialize using + operation (1+2+3+null+null+4+5+null+..)
        return to_string(root->val)+string("+")+serialize(root->left)+string("+")+serialize(root->right);

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //make a queue from the string
        queue<string> nodes;
        string node;
        //use stringstream to split the data
        stringstream ss(data);
        
       //use '+' to split the string and push those nodes
        while (getline(ss, node, '+')) {
            nodes.push(node);
        }
        //get the constructed tree from the helper
        return deserializeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
