#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> og,rev;
    LinkedListNode<int>* temp=head;
    while(temp){
        og.push_back(temp->data);
        temp=temp->next;
    }
    rev = og;
    reverse(rev.begin(),rev.end());
    return og==rev;

}
