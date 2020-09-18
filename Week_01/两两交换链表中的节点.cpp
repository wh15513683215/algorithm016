class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
   ListNode*p = new ListNode(0);
   p->next = head;
   ListNode *cur = p;
   while (head&&head->next) {
       ListNode *first = head;
       ListNode *second =head->next;
       cur->next = second;
       first->next = second->next;
       second->next = first;
       cur = first;
       head = first->next;
   }
   return p->next;
    }
}; //迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    while (!head||!head->next) return head;
    ListNode *p = head->next;
    ListNode *t = p->next;
    p->next = head;
    head->next = swapPairs(t);
    return p;
    }
}; //递归

