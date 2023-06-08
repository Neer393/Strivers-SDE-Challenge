#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
	if(k==0)	return head;
    Node* temp=head;
	int cnt=0;
	while(temp){
		cnt++;
		temp=temp->next;
	}
	if(cnt==k)	return head;
     if(k%cnt ==0)  return head;
	k=cnt-(k%cnt)-1;
	if(k==cnt)	return head;
	cnt=0;
	temp=head;
	while(temp && cnt!=k){
		temp=temp->next;
		cnt++;
	}
	Node* newpart = temp->next;
	temp->next=NULL;
	temp=newpart;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=head;
	return newpart;
}
