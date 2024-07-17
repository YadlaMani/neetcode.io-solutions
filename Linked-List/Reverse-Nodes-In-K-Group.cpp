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
//ex-: 1->2->3->4->5
//in first call we will have prev as 2 and next as 3 and 1->next=what the next reversed node returns
//in second all we will have prev as 4 and next as 5 and 3->next=what the next reversd node returns
//from link 5 we don't have enough nodes so 3->next=5
//4 is returned and 1->next=4
//and the prev head is returned 2->1->4->3->5
    ListNode* reverseKGroup(ListNode* head, int k) {
    //recursive approach
    //checking if we have enough nodes with the give head
      ListNode *curr=head;
      int c=0;
      while(curr && c<k){
        curr=curr->next;
        c++;
      }
      //if we have enough nodes to traverse
      if(c==k){
        //reverse the nodes upto k
        curr=head;
        ListNode* prev=NULL;
        ListNode* next;
        int c=0;
        while(curr && c<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        //we will prev node as the the head node and the next starting node to be traversed will be next if next is not null we apply recursion again
        if(next){
            //rejoining the reversed node the head node
            head->next=reverseKGroup(next,k);
        }
        //returning the prev node
        return prev;
      }
      //if we don't have enough nodes just return the head
      return head;
      

    }
};
