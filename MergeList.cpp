#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
//Linked list 1
void InsertAtTail1(Node *&head, int val)
{
    Node *temp1 = new Node(val);

    if (head == NULL)
    {
        head = temp1;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp1;
}
//Linked list 2
void InsertAtTail2(Node *&head, int val)
{
    Node *temp1 = new Node(val);

    if (head == NULL)
    {
        head = temp1;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp1;
}
//Merge two sorted linked list
/*
We use extra space for creating new nodes .We can do better than this too,by using in-place algorithm
*/
Node* Merge(Node* l1,Node* l2){                            
    Node* head=new Node(0);
    Node* temp=head;
    while(l1!=NULL && l2!=NULL){
        if(l1->data<l2->data){
            Node* newNode=new Node(l1->data);
            temp->next=newNode;
            l1=l1->next;
        }   
        else{
            Node* newNode=new Node(l2->data);
            temp->next=newNode;
            l2=l2->next;
        }
        temp=temp->next;
    }
    while(l1!=NULL){
        Node* newNode=new Node(l1->data);
            temp->next=newNode;
            l1=l1->next;
            temp=temp->next;
    }
    while(l2!=NULL){
        Node* newNode=new Node(l2->data);
            temp->next=newNode;
            l2=l2->next;
            temp=temp->next;
    }
    return head;
}
void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";

        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{

    Node* head1=NULL;
    Node* head2=NULL;
    int data, n, val;
    int arr1[4]={2,4,6,8};
    int arr2[4]={1,3,5,7};
    for (int i = 0; i < 4; i++)
    {
       
        InsertAtTail1(head1, arr1[i]);
    }
    for (int i = 0; i < 4; i++)
    {
       
        InsertAtTail2(head2, arr2[i]);
    }

    Display(head1);
    Display(head2);
    Node* newHead=Merge(head1,head2);
    Display(newHead);
    

   

    return 0;
}