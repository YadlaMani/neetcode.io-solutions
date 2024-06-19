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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL||list2==NULL){//handling the edge cases of null values
           return list1==NULL ? list2:list1;
        }
        ListNode *first=NULL;
        ListNode *last=NULL;
        while(list1&&list2){//traversing till one of the list pointer becomes null
            if(list1->val<list2->val){//adding them to the list according to the values
                if(first==NULL){
first=list1;
                    last=list1;
                }
                else{
                    last->next=list1;
                    last=last->next;
                }
                list1=list1->next;
}
            else{
                if(first==NULL){
                    first=list2;
                    last=list2;
                }
                else{
                    last->next=list2;
                    last=last->next;
                }
                list2=list2->next;
                
            }
        }
        if(list1){//if the list still not null adding the rest of the elements
            last->next=list1;
            last=last->next;
            list1=list1->next;
        }
        if(list2){
            last->next=list2;
            last=last->next;
            list2=list2->next;
        }
        return first;
    }
};
