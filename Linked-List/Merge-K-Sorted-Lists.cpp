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
    ListNode* mergeLists(ListNode* n1,ListNode* n2){
        ListNode dummy(0);//dummy pointer
        ListNode *tail=&dummy;//tail pointer
        while(n1 && n2){//keeping traversin until one list is empty
            if(n1->val < n2->val){//pushing the n1 val to keep ascending order
                tail->next=n1;
                n1=n1->next;
            }
            else{//pushing the n2 otherwise
                tail->next=n2;
                n2=n2->next;
            }
            tail=tail->next;

        }
        if(n1){//if still n1 traversal left
            tail->next=n1;
        }
        else{//if still n2 traversal left
            tail->next=n2;
        }
        return dummy.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;//edge cases
        if(n==1) return lists[0];
        ListNode *head=lists[0];//start from pointing towards first list
        for(int i=1;i<n;i++){//then traverse through the list and keep merging with the main list
            head=mergeLists(head,lists[i]);
        }
        return head;
    }
};
