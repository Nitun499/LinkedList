#include <bits/stdc++.h>

using namespace std;
// int GCD(int a,int b){
//   return b==0?a:GCD(b,a%b);
// }
class Node
{
public:
    int data;
    Node *next;
};
//Functio for inserting at tail
void InsertAtTail(Node *&head, int val)
{
    Node *temp1 = new Node();
    temp1->data = val;
    temp1->next = NULL;
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
//At beginning 
void InsertAtBegin(Node *&head, int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
}
//Deletion of node at any position u want
void Delete(Node *&head, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
//function for desplaying
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
//function for Reversing linked list ->Iterative approach
void Reverse(Node* &head){
    Node* prev=NULL;
    Node* current=head;
    while(current!=NULL){
        Node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;

    }
    head=prev;


}
//Recursive printing elements 
void PrintReverse(Node* head){
    if(head==NULL){
        return;
    }
    PrintReverse(head->next);
    cout<<head->data<<" ";

}

int main()
{
    Node *head = NULL;
    int data, n, val;
    cout << "How many element u want " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data " << endl;
        cin >> data;
        InsertAtTail(head, data);
    }

    Display(head);
    cout << "Position deletion " << endl;
    cin >> val;

    Delete(head, val);
    Display(head);
    cout<<"Before reversing "<<endl;
    Reverse(head);
    cout<<"After reversing "<<endl;
    Display(head);
    PrintReverse(head);
    // Display(head);
    return 0;
}