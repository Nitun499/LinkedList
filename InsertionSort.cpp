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
void InsertNode(Node* &head,int data){
    Node* newNode= new Node(data);
    Node* curr=head;
    if(head==NULL){
        head=newNode;
        return;
    }
    else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newNode;
    }
}  
  
Node* InsertionSort(Node* head)
{
    Node* dummy=new Node(-1);
    dummy->next=head;
    Node* prev=dummy;
     Node* curr=head;
     while(curr!=NULL){
         if(curr->next && curr->next->data<curr->data){
             while(prev->next && prev->next->data<curr->next->data){
                 prev=prev->next;
             }
             Node* temp=prev->next;
             prev->next=curr->next;
             curr->next=curr->next->next;
             prev->next->next=temp;
             prev=dummy;
         }
         else{
             curr=curr->next;
         }
     }
     return dummy->next;

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
    int arr[]={4,1,3,5,2,7};
    for(auto a: arr){
        InsertNode(head,a);
    }
    Display(head);
    Node* newhead=InsertionSort(head);
    Display(newhead);
    return 0;
}