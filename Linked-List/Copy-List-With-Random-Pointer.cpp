/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;//store a map which creates all the copies of the initial linked list
        Node *temp=head;
        while(temp){
            Node *nn=new Node(temp->val);//creating a copy
            mp[temp]=nn;//and assignining the old node to a new node
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node *nn=mp[temp];//get the node
           
            nn->next= mp[temp->next];//assign node of next accoriding to the old node
            nn->random=mp[temp->random];//assign the random according to the old node
            temp=temp->next;

        }
        return mp[head];//return head
    }
};
