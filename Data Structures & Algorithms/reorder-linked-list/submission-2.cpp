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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* cur=head;
        ListNode* next=nullptr;
        ListNode* prev=nullptr;
        while(temp){
            cur=temp;
            if(cur==head){
                next=cur->next;
                cur->next=nullptr;
            }
            else{ 
                next=cur->next;
                cur->next=prev;
            }
            prev=cur;
            temp=next;

        }
        head=prev;
        return head;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* l1=head;
        ListNode* l2=head;  
        int cnt=0,i=0;
        while(fast and fast->next){
            cnt++;
            slow=slow->next;
            fast=fast->next->next;
        }
        l2=slow->next;
        slow->next=nullptr;
        l2=reverseList(l2);
        while(l2){
            ListNode* n1 = l1->next;
            ListNode* n2 = l2->next;

            l1->next = l2;
            l2->next = n1;

            l1 = n1;
            l2 = n2;
        }
    }
};
