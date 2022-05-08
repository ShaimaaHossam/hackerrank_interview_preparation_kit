/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return nullptr;
        
        unordered_map<Node*, Node*> map;
        
        Node *copy = new Node(0);
        Node *c_ptr = copy;
        Node *o_ptr = head;

        
        while(o_ptr != NULL){
           Node *newNode = new Node(o_ptr->val);
            c_ptr->next = newNode;
            c_ptr = c_ptr->next;
            map[o_ptr] = c_ptr;
            o_ptr = o_ptr->next;
        }
        
        o_ptr = head;
        c_ptr = copy->next;
        
        while(o_ptr!=NULL){
            if(o_ptr->random != NULL)
               c_ptr->random = map.find(o_ptr->random)->second;
            
            o_ptr = o_ptr->next;
            c_ptr = c_ptr->next;
            
        }
        
        return copy->next;
    }
    
    
};
