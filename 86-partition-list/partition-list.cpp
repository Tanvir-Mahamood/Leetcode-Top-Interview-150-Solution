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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode();
        ListNode* smallPtr = smallHead;
        ListNode* bigHead = new ListNode();
        ListNode* bigPtr = bigHead;

        while(head) {
            if(head->val < x) {
                smallPtr->next = head;
                smallPtr = smallPtr->next;
            }
            else {
                bigPtr->next = head;
                bigPtr = bigPtr->next;
            }
            head = head->next;
        }

        smallPtr->next = bigHead->next;
        bigPtr->next = nullptr;
        ListNode* ans = smallHead->next;
        delete bigHead;
        delete smallHead;

        return ans;

    }
};