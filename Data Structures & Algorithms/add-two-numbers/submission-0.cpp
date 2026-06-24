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
        ListNode* dummy=new ListNode(-1);
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* temp=dummy;
        int carry=0;
        while(temp1 || temp2){
            int a=temp1?temp1->val:0;
            int b=temp2?temp2->val:0;
            int sum=a+b+carry;
            if(sum>9){
                carry=sum/10;
                sum%=10;
            }
            else{
                carry=0;
            }
            ListNode* newNode=new ListNode(sum);
            dummy->next=newNode;
            dummy=dummy->next;
            temp1=temp1?temp1->next:nullptr;
            temp2=temp2?temp2->next:nullptr;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            dummy->next=newNode;
        }
        return temp->next;
    }
};
