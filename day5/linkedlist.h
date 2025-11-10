#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *createList(vector<int>& v){
    if(v.empty()) return nullptr;
    ListNode *dummy = new ListNode();
    ListNode* curr = dummy;
    for(int& x : v){
        curr -> next = new ListNode(x);
        curr = curr -> next;
    }
    return dummy -> next;
}
void printList(ListNode* head){
    ListNode* curr = head;
    cout << "List: ";
    while(curr != nullptr){
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n\n";
}
void deleteList(ListNode *head){
    ListNode *curr = head;
    while(curr != nullptr){
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }
}
void insertFront(ListNode*& head, int x){
    ListNode *front = new ListNode(x);
    front -> next = head;
    head = front;
}
void insertBack(ListNode*& head, int x){
    ListNode *back = new ListNode(x);
    if(head == nullptr){
        head = back;
        return;
    }
    ListNode *curr = head;
    while(curr -> next != nullptr){
        curr = curr -> next;
    }
    curr -> next = back;
}
void deleteFront(ListNode*& head){
    if(head == nullptr) return;
    ListNode* front = head;
    head = head -> next;
    delete front;
}
void deleteBack(ListNode*& head){
    if(head == nullptr) return;
    if(head -> next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr -> next != nullptr){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = nullptr;
    delete curr;
}
void deleteIndex(ListNode*& head, int index){
    if(head == nullptr) return;
    ListNode *dead;
    if(index == 0){
        deleteFront(head);
        return;
    }
    ListNode *prev = head;
    while(prev != nullptr && index > 1){
        prev = prev->next;
        index--;
    }
    if(prev == nullptr || prev -> next == nullptr) return;
    dead = prev->next;
    prev ->next = dead->next;
    delete dead;
}
void deleteValue(ListNode*& head, int value){
    if(head == nullptr) return;
    ListNode *dead;
    if(head->val == value){
        deleteFront(head);
        return;
    }
    ListNode *prev = head;
    ListNode *curr = head -> next;
    while(curr != nullptr){
        if(curr->val == value){
            dead = curr;
            prev -> next = curr -> next;
            delete dead;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
    return;
}