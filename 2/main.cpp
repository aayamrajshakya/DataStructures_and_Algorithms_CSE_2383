//Name: Aayam Raj Shakya (as5160)


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *tail;
};

class Stack{
    public:
    Node *top, *tail;

    Stack(){
        top=tail=NULL;
    }

    void push(int value){
        Node *tmp = new Node;
        tmp->data = value;
        tmp->next = NULL;
        if (top==NULL){
            top=tail=tmp;
        }else{
            tail->next=tmp;
            tail=tmp;
        }
    }

    void display(){
        Node *print = top;
        while(print!=NULL){
            cout<<print->data<<" ";
            print=print->next;
        }
        cout<<endl;
    }

    void peek(int &tmp){
        if(top!=NULL){
            tmp= top->data;
        }else{
            cout<<"Stack is empty";
        }

    }

    void pop(){
        Node *tmp = top;
        if(top==NULL){
            cout<<"The stack is empty; nothing to be deleted";
        }else{
            top=top->next;
             delete tmp;
        }
    }
};

int main()
{
    Stack S;
    int tmp;
    S.push(5);
    S.peek(tmp);
    cout << tmp << endl;
    S.push(33);
    S.push(1);
    S.push(7);
    S.peek(tmp);
    cout << tmp << endl;
    S.push(33);
    S.push(12);
    S.display();
    S.pop();
    S.display();
    S.push(14);
    S.display();
    S.pop();
    S.pop();
    S.display();
    S.pop();
    S.pop();
    S.display();
    S.peek(tmp);
    cout << tmp << endl;
}

