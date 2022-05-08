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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divideAndConquer(lists, 0, lists.size()-1);
    }
    ListNode* divideAndConquer(vector<ListNode*>& lists, int start, int end) {
        if(start > end) return nullptr;
        if(start == end) return lists[start];
        int mid = start + (end-start)/2;
        
        return mergeTwoLists(divideAndConquer(lists, start, mid), divideAndConquer(lists, mid+1, end));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;
        
        while(l1 != NULL || l2 != NULL){
             ListNode *node = new ListNode();
            
            if(l2 != NULL && l1 !=NULL){
                if(l1->val < l2->val){
                    p->next = l1;
                    l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            
            else if(l1 == NULL){
                p->next = l2;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                p->next = l1;
                l1 = l1->next;
            }
            
            p=p->next;
        }
        
        return dummy->next;
    }
    
    
};
