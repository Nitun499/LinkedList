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
// Node* Rotation(Node* head,int k){
//     vector<int> v;
//     Node* curr=head;
//     Node* dummy=new Node(-1);
//     Node* temp1=dummy;
//     while(curr){
//         v.push_back(curr->data);
//         curr=curr->next;
//     }
//     for(int i=0;i<k;i++){
//         int temp=v[v.size()-1];
//         for(int j=v.size()-1;j>0;j--){
//             v[j]=v[j-1];
//         }
//         v[0]=temp;
//     }
//     int l=0;
//    for(int l=0;l<=v.size()-1;l++){
//         Node* newnode=new Node(v[l]);
//         temp1->next=newnode;
//         temp1=temp1->next;
//     }
//     return dummy->next;
// }
    Node* SwapInPair(Node*  head){
        Node* dummy=new Node(-1);
        dummy->next=head;
        Node* prev=dummy;
        
        Node* curr=head;
        while(curr!=NULL && curr->next!=NULL){
           prev->next=curr->next;
           curr->next=curr->next->next;
           prev->next->next=curr;
           curr=curr->next;
           prev=prev->next->next;
        }
        return dummy->next;
    
    }
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
     int arr[6]={1,2,3,4,5,6};
     for(int i=0;i<6;i++){
         InsertNode(head,arr[i]);
     }
    Display(head);
    // Node* newhead=Rotation(head,2);
    // Display(newhead);
    Node* newhead=SwapInPair(head);
    Display(newhead);
    return 0;
}