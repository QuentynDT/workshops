//Leetcode 206: Reverse Linked List
#include "linkedlist.h"
ListNode *reverse(ListNode* head){
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        // p    c    n
        // D -> 2 -> 6 -> 7 -> 0 -> 4
        //D  <- 2    6 -> 7 -> 0 -> 4
        //      p    c    n
        //D  <- 2    6 -> 7 -> 0 -> 4
        //D  <- 2 <- 6    7 -> 0 -> 4
        //                     p    c    n
        //D  <- 2 <- 6 <- 7 <- 0    4 -> N
        //D  <- 2 <- 6 <- 7 <- 0 <- 4    N
        //curr = nullptr;
    }
    return prev;
}

// 
int main(){
    vector<int> v = {2, 6, 7, 0, 4};
    ListNode* myList = createList(v);
    printList(myList);

    myList = reverse(myList);
    printList(myList);
    return 0;
}