#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;
    ListNode *prev;
};

class LinkedList{
public:
    ListNode *head,*tail;

    LinkedList(){
        head = tail = NULL;
    }

    void append(int value){
        ListNode *newNode = new ListNode;
        newNode->data = value;
        newNode->next = newNode->prev = NULL;
        if(head == NULL){
            head = newNode;
            tail = head;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    bool search(int data) {
        ListNode* tmp = head;
        while (tmp != nullptr) {
            if (tmp->data == data) {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
};