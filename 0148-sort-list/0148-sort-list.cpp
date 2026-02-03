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
    ListNode* mergeList(ListNode *node1, ListNode* node2) {
        ListNode* newNode = new ListNode(0);
        ListNode* curr = newNode;

        while(node1 && node2) {
            if(node1->val <= node2->val) {
                curr->next = node1;
                node1 = node1->next;
            }
            else {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }

        // Remaining nodes
        if(node1) curr->next = node1;
        if(node2) curr->next = node2;

        return newNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        // Tortoise and Hare algorithm (finding midpoint of a LL)
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr; // End of first half.

        ListNode* L1 = sortList(head);
        ListNode* L2 = sortList(slow);

        return mergeList(L1, L2);
    }
};