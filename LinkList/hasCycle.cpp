/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class hasCycle {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        while (slow_ptr != nullptr && fast_ptr != nullptr) {
            slow_ptr = slow_ptr->next;
            if (fast_ptr->next != nullptr){
                fast_ptr = fast_ptr->next->next;
            } else {
                return false;
            }
            
            if (slow_ptr == fast_ptr) {
                return true;
            }
        }
        return false;
    }
};