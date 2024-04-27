#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

class LinkedList{
    public:
    Node *head,*tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void prepend(int value){
        Node *newNode = new Node;
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
    
    void append(int value){
        Node *newNode = new Node;
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
        Node *current = head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    
    bool remove(int value){
        Node *current = head;
        Node *previous = head;
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
        Node *tracker1=tail;
        Node *tracker2= NULL;
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
        Node *printReverse = tail;
        while(printReverse!=NULL) {
            cout << printReverse->data << " ";
            printReverse = printReverse->prev;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList LL; 
    LL.append(5); 
    LL.append(33); 
    LL.append(1); 
    LL.append(7); 
    LL.append(33); 
    LL.append(12); 
    LL.display(); 
    LL.remove(33); 
    LL.display(); 
    LL.prepend(12); 
    LL.display(); 
    LL.remove(13); 
    LL.display(); 
    LL.tailDisplay();
    LL.tailRemove(12);
    LL.display();
    return 0;
}









