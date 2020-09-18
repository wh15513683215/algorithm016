class Solution {
public:
ListNode* reverseList(ListNode* head) {
   ListNode *cur =NULL,*pre =head;
   while (pre) {
       ListNode *t = pre->next;
       pre->next =cur;
       cur = pre;
       pre =t;
   }
   return cur;
}
};//O(n) O(n) 迭代
class Solution {
public:
ListNode* reverseList(ListNode* head) {
    if (!head||!head->next) 
    return head;
    ListNode *p = reverseList(head->next);
    head->next->next=head;
    head->next =NULL;
    return p;
}
};//O(n) O(n) 递归
