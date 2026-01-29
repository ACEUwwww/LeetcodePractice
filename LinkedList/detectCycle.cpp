/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        bool hasCycle = false;
        while (slow_ptr != nullptr && fast_ptr != nullptr) {
            slow_ptr = slow_ptr->next;
            if (fast_ptr->next != nullptr){
                fast_ptr = fast_ptr->next->next;
            } else {
                return nullptr;
            }
            
            if (slow_ptr == fast_ptr) {
                hasCycle = true;
                break;
            }
        }

        ListNode* new_ptr = head;
        while (hasCycle) {
            slow_ptr = slow_ptr ->next;
            while (slow_ptr != fast_ptr) {
                if (new_ptr == slow_ptr) {
                    return new_ptr;
                }
                slow_ptr = slow_ptr->next;
            }
            if (new_ptr == slow_ptr)
                return new_ptr;
            new_ptr = new_ptr -> next;
        }

        return nullptr;
    }
};