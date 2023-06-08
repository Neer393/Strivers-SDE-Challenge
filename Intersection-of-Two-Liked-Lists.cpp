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

Node* solve(Node* longer,Node* shorter,int longcnt,int shortcnt){
	Node* temp=longer;
	while(longcnt!=shortcnt && temp){
		longcnt--;
		temp=temp->next;
	}
	Node *ptr1=shorter;
	Node* ptr2 = temp;
	while(ptr1 && ptr2){
		if(ptr1==ptr2)	return ptr1;
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return NULL;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int cnt1=0,cnt2=0;
	Node*temp=firstHead;
	while(temp){
		cnt1++;
		temp=temp->next;
	}
	temp=secondHead;
	while(temp){
		cnt2++;
		temp=temp->next;
	}
	if(cnt1<=cnt2){
		return solve(secondHead,firstHead,cnt2,cnt1);
	}
	return solve(firstHead,secondHead,cnt1,cnt2);
}
