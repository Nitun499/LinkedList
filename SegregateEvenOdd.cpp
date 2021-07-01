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
Node* Segregate(Node* head){
    Node* dummyEven=new Node(-1);
    Node* dummyOdd=new Node(-1);
    Node* evenT=dummyEven;
    Node* oddT=dummyOdd;
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data%2!=0){
            oddT->next=curr;
            oddT=oddT->next;
        }
        else{
            evenT->next=curr;
            evenT=evenT->next;
        }
        curr=curr->next;
    }
    evenT->next=dummyOdd->next;
    oddT->next=NULL;
    return dummyEven->next;
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
    Node* head=NULL;
    int arr[]={3,5,4,7,8,12,1,6,8,9,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        InsertAtTail1(head,arr[i]);
    }
    Display(head);
    Node* newHead=Segregate(head);
    Display(newHead);


    return 0;
}