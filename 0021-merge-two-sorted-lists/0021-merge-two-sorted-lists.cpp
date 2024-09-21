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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        if (l1->val > l2->val) std::swap(l1, l2);
        ListNode* result = l1;
        
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* temp = nullptr;
            while (l1 != nullptr && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            std::swap(l1, l2);
        }
        
        return result;
    }
};