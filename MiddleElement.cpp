#include <bits/stdc++.h>
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
/*** Finding mid of linked list is very interesting problem .
    So,best approach to find medium of linked list we can use two pointer approach,
    Slow and Fast pointer.
    Idea is:
    ->If our fast pointer moves at null,then elements are even and if not then elements are even.
    and slow pointer will be our mid element 
***/
//Middle element
// Node *Middle(Node *head)
// {
//     Node *slow = head;
//     Node *fast = head;
//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }
Node *Delete(Node *ListHead, int val)
{
    if (ListHead->data == val)
    {
        Node *temp = ListHead;
        ListHead = temp->next;
        delete temp;
        return ListHead;
    }
    Node *curr = ListHead;
    while (curr->next->data != val)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return ListHead;
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


void Swap(int & x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
void Swapdata(Node* head){
    // Node* curr=head;
    while(head!=NULL && head->next!=NULL){
        Swap(head->data,head->next->data);
        head=head->next->next;
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
    // Node* newHead=Merge(head1,head2);
    // Display(newHead);
    Swapdata(head1);
    Swapdata(head2);
    Display(head1);
    Display(head2);

    // Node *mid = Middle(head);
    // cout << mid->data;

    return 0;
}