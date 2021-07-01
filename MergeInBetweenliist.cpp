#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* Merge(Node* &list1,Node* &list2,int a,int b){
    Node* preX=NULL,*currX=list1;
    while(currX && currX->data!=a){
        preX=currX;
        currX=currX->next;
    }
    Node* currY=list1;
    while(currY && currY->data!=b){
        currY=currY->next;
    }
    Node* tail=list2;
    while(tail->next){
        tail=tail->next;
    }
    if(preX!=NULL){
        preX->next=list2;
    }
    else{
        list1=list2;
    }
    
    tail->next=currY->next;
    return list1;
}
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

int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    int arr1[5]={1,2,3,4,5};
    int arr2[3]={7,8,9};
    for (int i = 0; i < 5; i++)
    {
       
        InsertAtTail1(head1, arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
       
        InsertAtTail2(head2, arr2[i]);
    }

    Display(head1);
    Display(head2);
    Node* newHead=Merge(head1,head2,1,4);
    Display(newHead);
    
  
    return 0;
}
