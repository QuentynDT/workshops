//Leetcode 876: Middle of the Linked List
#include "linkedlist.h"
ListNode *middleList(ListNode* head){
    ListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *ans = new ListNode(slow->val);
    return ans;
}
int main(){
    vector<int> v = {3, 4, 5, 6, 1, 7};
    ListNode* myList = createList(v);
    printList(myList);

    myList = middleList(myList);
    printList(myList);
    return 0;
}