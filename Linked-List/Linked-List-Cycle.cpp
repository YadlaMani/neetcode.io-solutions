/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;//maintain a slow and faster pointer
        ListNode *fast=head;
        int c=0;
        while(fast&&fast->next){//check for null fast pointer
            c++;//increase count
            fast=fast->next->next;//move faster pointer by two units
            slow=slow->next;//slow pointer by one unit
            if(fast==slow){//check if they are same
                return true;
            }
        }
        return false;
    }
};
