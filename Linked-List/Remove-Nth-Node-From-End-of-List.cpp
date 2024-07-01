class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        
        for (int i = 0; i < n; ++i) {//first move head by n nunits
            if (fast == nullptr) return head;
            fast = fast->next;
        }
        
        
        if (fast == nullptr) {//if the first is at null then we have to remove the firs element
            return head->next;
        }
        
        
        while (fast->next) {//run till fast not null
            fast = fast->next;
            slow = slow->next;
        }
        
         slow->next = slow->next->next;//change the slow pointer
        
        return head;
    }
};
