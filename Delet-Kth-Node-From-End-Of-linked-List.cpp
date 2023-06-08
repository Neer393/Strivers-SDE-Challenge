/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    int n=0;
    Node* temp =head;
    while(temp){
        n++;
        temp=temp->next;
    }
    if(n==K)    return head->next;
    int cnt=0;
    temp=head;
    while(temp && cnt!=n-K-1){
        temp=temp->next;
        cnt++;
    }
    temp->next=temp->next->next;
    return head;
}
