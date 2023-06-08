/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

 #include <bits/stdc++.h>

void insertattail(Node* &head,Node* &tail,int val){
	Node* n = new Node(val);
	if(head==NULL){
		head=n;
		tail=n;
		return;
	}
	tail->child=n;
	tail=tail->child;
}

Node* flattenLinkedList(Node* head) 
{
	vector<int>vec;
	Node* temp=head;
	while(temp){
		vec.push_back(temp->data);
		Node* tempo = temp->child;
		while(tempo){
			vec.push_back(tempo->data);
			tempo=tempo->child;
		}
		temp=temp->next;
	}
	// for(auto i:vec)	cout<<i<<" "<<", ";
	// cout<<endl;
	Node* anshead=NULL;
	Node* anstail =NULL;
	sort(vec.begin(),vec.end());
	for(auto i:vec){
		insertattail(anshead,anstail,i);
	}
	return anshead;
}
