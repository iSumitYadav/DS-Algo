#include<bits/stdc++.h>
using namespace std;

struct Node{
    int d;
    Node *next;
};

void prepend(Node **head, int key){
    Node *temp = new Node;
    temp->d = key;
    temp->next = *head;
    *head = temp;
    return;
}

void printList(Node *head){
    while(head){
        cout << head->d << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertInSortedOrder(Node **head, int key){
    Node *temp = new Node;
    temp->d = key;

    if(!(*head) || (*head)->d >= key){
        temp->next = *head;
        *head = temp;
        return;
    }

    Node *curr = *head, *prev;

    while(curr && curr->d < key){
        prev = curr;
        curr = curr->next;
    }

    temp->next = curr;
    prev->next = temp;

    return;
}

Node *sortLinkedList(Node *head){
    if(!head || !head->next)
        return head;

    Node *result = NULL;

    while(head){
        insertInSortedOrder(&result, head->d);
        head = head->next;
    }

    return result;
}

int main(){
    Node *head = NULL;
    prepend(&head, -1);
    prepend(&head, 1);
    prepend(&head, 11);
    prepend(&head, 10);
    prepend(&head, 5);
    prepend(&head, 16);
    prepend(&head, 15);
    prepend(&head, 6);
    prepend(&head, 7);
    prepend(&head, 9);

    printList(head);

    head = sortLinkedList(head);

    printList(head);

    return 0;
}
