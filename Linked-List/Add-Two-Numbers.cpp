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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ll->linked List
        ListNode *temp1=l1;//pointer one for 1st ll
        ListNode *temp2=l2;//pointer two for 2nd ll
        ListNode *front=NULL,*rear=NULL;//new pointer for our ans
        int carry=0;//carry
        while(temp1 || temp2){//running till both ll reaches end
            int a=0,b=0,ele=0;
            if(temp1){//get value from ll1 if not null
                a=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){//getting the val from ll2 if not null
                b=temp2->val;
                temp2=temp2->next;
            }
            ele=a+b+carry;//adding them with carry
            cout<<ele<<endl;
            carry=ele/10;//caculating the carry
            ListNode *nn=new ListNode(ele%10);//creating nn and inserting the element
            if(front==NULL){
                front=nn;
                rear=nn;
            }
            else{
                rear->next=nn;
                rear=nn;
            }



        }
        if(carry){//limiting case if there is still carry add it to the list
            ListNode *nn=new ListNode(1);
            rear->next=nn;
            rear=nn;
        }
        return front;
    }
};
