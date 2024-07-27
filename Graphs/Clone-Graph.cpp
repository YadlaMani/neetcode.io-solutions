/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *dfs(Node* node,unordered_map<Node*,Node*>&oldToNew){
        if(oldToNew.find(node)!=oldToNew.end()){//if we have already mapped the old node to new node return the new node
            return oldToNew[node];
        }
        Node *copy=new Node(node->val);//else create a copy
        oldToNew[node]=copy;//and assgin new node to the old node
        for(Node* neighbor:node->neighbors){//and traverse the neighbours
            copy->neighbors.push_back(dfs(neighbor,oldToNew));//and add them to the the copy neighbors
        }
        return copy;//return the copied node
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        //Map a map to keep track of the newly created nodes
        unordered_map<Node*,Node*>oldToNew;
        return dfs(node,oldToNew);
    }
};
