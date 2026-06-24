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
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevTail = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* kth = curr;

            for (int i = 1; i < k && kth; i++)
                kth = kth->next;

            if (!kth)
                break;

            ListNode* nextGroup = kth->next;

            ListNode* newHead = reverse(curr, k);

            prevTail->next = newHead;
            curr->next = nextGroup;

            prevTail = curr;
            curr = nextGroup;
        }

        return dummy.next;
    }
};