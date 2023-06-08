#include <bits/stdc++.h> 

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

void insertAtTail(Node<int>* &head,Node<int>* &tail,int val){
    Node<int>* n = new Node<int>(val);
    if(!head){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=tail->next;
}

Node<int>* solve(Node<int>* &first, Node<int>* &second){
    Node<int>* anshead=NULL;
    Node<int>* anstail=NULL;
    Node<int>* temp1=first;
    Node<int>* temp2 = second;
    while(temp1 && temp2){
        if(temp1->data<=temp2->data){
            insertAtTail(anshead,anstail,temp1->data);
            temp1=temp1->next;
        }
        else{
            insertAtTail(anshead,anstail,temp2->data);
            temp2=temp2->next;
        }
    }
    if(temp1){
        anstail->next=temp1;
    }
    if(temp2){
        anstail->next=temp2;
    }
    return anshead;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    return solve(first,second);
}
