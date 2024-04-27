#include <iostream>
using namespace std;

class NodeLL{
    public:
    int data;
    NodeLL *next;
    NodeLL *prev;

};

class LinkedList{
    public:
    NodeLL *head,*tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void prepend(int value){
        NodeLL *newNode = new NodeLL;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL){
            head=newNode;
            tail=head;
        }else{
            newNode->next = head;
            head->prev=newNode;
            head = newNode;
        }
    }
    
    bool search(int value) {
        NodeLL* tmp = head;
        while (tmp != nullptr) {
            if (tmp->data == value) {
                return true; 
            }
            tmp = tmp->next;
        }
        return false; 
    }
    
    void append(int value){
        NodeLL *newNode = new NodeLL;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL){
            head = newNode;
            tail = head;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    
    
    void display(){
        NodeLL *current = head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    
    bool remove(int value){
        NodeLL *current = head;
        NodeLL *previous = head;
        while(current!=NULL){
            if(current->data==value and current==head){
                head=current->next;
                free(current);
                break;
            }else if(current->data==value){
                current->prev->next=current->next;
                current->next->prev=current->prev;
                if(current==tail){
                    tail=previous;
                }
                free(current);
                return true;
            }
                previous=current;
                current=current->next;
            }
            return false;
        }

        bool tailRemove(int value){
        NodeLL *tracker1=tail;
        NodeLL *tracker2= NULL;
        while(tracker1!=NULL){
            if(tracker1->data==value){
                if(tracker1->next!=NULL){
                    tracker1->next->prev=tracker1->prev;
                }
                if(tracker1->prev!=NULL){
                    tracker1->prev->next=tracker1->next;
                }
                if(tracker1==head){
                    head=tracker1->next;
                }
                if(tracker1==tail){
                    tail=tracker1->prev;
                }
                free(tracker1);
                return true;
            }
            tracker2=tracker1;
            tracker1=tracker1->prev;
        }
        return false;
    }

    void tailDisplay(){
        NodeLL *printReverse = tail;
        while(printReverse!=NULL) {
            cout << printReverse->data << " ";
            printReverse = printReverse->prev;
        }
        cout<<endl;
    }

};
