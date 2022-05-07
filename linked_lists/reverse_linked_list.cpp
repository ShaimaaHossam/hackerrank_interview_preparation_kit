using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *tmp = NULL;
        ListNode *curr = head;
        
         while(curr != NULL){
             tmp = curr->next;
             curr->next = prev;
             prev = curr;
             curr = tmp;
         }
        return prev;
    }
};
