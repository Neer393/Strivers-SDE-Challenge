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

Node* solve(Node* &head,int n,int b[],int idx){
	if(idx>=n || !head)	return head;
	if(b[idx]==0)	return solve(head,n,b,idx+1);
	if(b[idx]==1){	head->next=solve(head->next,n,b,idx+1);
	return head;}
	Node* prev=NULL;
	Node* curr=head;
	Node* upcoming;
	int cnt=0;
	while(curr!=NULL && cnt<b[idx]){
		upcoming=curr->next;
		curr->next=prev;
		prev=curr;
		curr=upcoming;
		cnt++;
	}
	if(upcoming)	head->next = solve(upcoming,n,b,idx+1);
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node* ans = head;
	return solve(ans,n,b,0);
}
