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
};
