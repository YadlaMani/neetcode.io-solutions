/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      
        ListNode *curr=head;//keeps the track of the current node
        ListNode *prev=NULL,*next=NULL;
        while(curr){
            next=curr->next;//assign the next node 
            curr->next=prev;//pointer of the current node is pointed to previous node
            prev=curr;//and prev node is now shifted to current node
            curr=next;//current node is set to next node
            
            
        }
        return prev;
    }
};
