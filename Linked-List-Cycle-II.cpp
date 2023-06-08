/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    Node* slow =head;
    Node* fast=head;
    bool cycle=false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cycle=true;
            break;
        }
    }
    if(!cycle)  return NULL;
    fast=head;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
