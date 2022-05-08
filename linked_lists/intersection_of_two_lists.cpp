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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        
        int steps = 0;
        
        if(l1 > l2){
            while(steps < l1-l2){
                temp1 = temp1->next;
                steps++;
            }
        }
        else if(l1 < l2){
            while(steps < l2-l1){
                temp2 = temp2->next;
                steps++;
            }
        }
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        return nullptr;
    }
    int getLength(ListNode *head) {
        ListNode*ptr = head;
        int len = 0;
        if(head == NULL)
            return 0;
        else{
            while(ptr != NULL){
                len ++;
                ptr = ptr->next;
            }
        }
        return len;
    }
};
