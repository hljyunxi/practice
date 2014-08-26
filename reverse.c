#include <stdio.h>

typedef struct node{
    struct node * next;
    int data;
} node;

node * reverse(node * head){
    node * curr = head, prev = NULL, next = NULL;

    if(head == NULL)
        return NULL;
    
    while(head){
        head = head->next;
    }

    while(curr!=head){
        next = curr->next;
        head->next = curr;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return head;
}
