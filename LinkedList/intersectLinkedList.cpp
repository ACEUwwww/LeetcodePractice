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
/*  Brute Force 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != NULL) {
            while (B != NULL) {
                if (A == B) {
                    return A;
                }
                B = B -> next;
            }
            A = A -> next;
            B = headB;
        }
        return NULL;
    }
*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            if (pA != nullptr) {
                pA = pA -> next;
            } else {
                pA = headB;
            }
            if (pB != nullptr) {
                pB = pB -> next;
            } else {
                pB = headA;
            }
        }
        return pA;
    }
};