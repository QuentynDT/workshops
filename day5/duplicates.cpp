//Leetcode 83: Remove Duplicates from Sorted List
#include "linkedlist.h"
ListNode *deleteDuplicates(ListNode* head){
    ListNode *curr = head, *dead;
    while (curr != nullptr){
        while(curr -> next != nullptr && curr->val == curr->next->val){
            dead = curr->next;
            curr -> next = curr->next->next;
            delete dead;
        }
        curr = curr->next;
    }
    return head;
}
int main(){
    vector<int> v = {3, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9, 9};
    ListNode* myList = createList(v);
    printList(myList);

    myList = deleteDuplicates(myList);
    printList(myList);
    return 0;
}