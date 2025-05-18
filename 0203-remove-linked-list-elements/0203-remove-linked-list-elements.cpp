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
    ListNode* removeElements(ListNode* head, int val) {
        // Handle case where head is null
        if (!head) {
            return nullptr;
        }
        
        // Move head forward if it contains val
        while (head && head->val == val) {
            head = head->next;
        }
        
        // If list is empty after moving head
        if (!head) {
            return nullptr;
        }
        
        // Use two pointers to traverse and remove nodes
        ListNode* current = head;
        ListNode* prev = nullptr;
        
        while (current) {
            if (current->val == val) {
                // Skip the current node
                prev->next = current->next;
            } else {
                // Move prev only if no removal
                prev = current;
            }
            // Move current forward
            current = current->next;
        }
        
        return head;
    }
};