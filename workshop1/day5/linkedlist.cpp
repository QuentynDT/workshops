#include "linkedlist.h"
int main(){
    vector<int> v = {5, 6, 3, 4, 2, 1};
    ListNode* myList = createList(v);
    printList(myList);

    insertFront(myList, 9);
    printList(myList);

    insertBack(myList, 8);
    printList(myList);

    deleteFront(myList);
    printList(myList);

    deleteBack(myList);
    printList(myList);

    deleteIndex(myList, 3);
    printList(myList);

    deleteValue(myList, 6);
    printList(myList);

    deleteList(myList);
    return 0;
}
//comparing:    insertion   deletion   random access 

//vectors       O(n)          O(n)          O(1)

//linked list   O(1)          O(1)          O(n)
