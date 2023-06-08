#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
	        Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

void insertAtTail(Node* &head,Node* &tail,int val){
    Node* n = new Node(val);
    if(!head){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=tail->next;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    
    int carry=0;
    Node* temp1=head1;
    Node* temp2=head2;
    Node* anshead=NULL;
    Node* anstail=NULL;
    while(temp1 && temp2){
        int sum = temp1->data+temp2->data+carry;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(anshead,anstail,digit);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1){
        int sum = temp1->data+carry;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(anshead,anstail,digit);
        temp1=temp1->next;
    }
    while(temp2){
        int sum = temp2->data+carry;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(anshead,anstail,digit);
        temp2=temp2->next;
    }
    if(carry)   insertAtTail(anshead, anstail, carry);
    return anshead;
}
