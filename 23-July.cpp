/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/class Solution
{
    public:

    Node* segregate(Node *head) {
        Node* temp = head;
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        while(temp != NULL) {
            if(temp->data == 0) count_0++;
            else if(temp->data == 1) count_1++;
            else count_2++;
            
            temp = temp->next;
        }

        temp = head;

        while(count_0--) {
            temp->data = 0; 
            temp = temp->next;
        }
        while(count_1--) {
            temp->data = 1;
            temp = temp->next;
        }
        while(count_2--) {
            temp->data = 2;
            temp = temp->next;
        }
        
        return head;
        
    }
};
     
