#include <stdio.h>

/*
 *链表反转
 */

typedef struct node {
    struct node * next;
    int data;
} node_t;

void reverse(node_t *& head){
    if(NULL == head)
        return ; 

    node_t * new_root = NULL, * next;
    while(head){
        next = head->next;
        head->next = new_root;
        new_root = head;
        head = next;
    }

    head = new_root;
}


node_t * reverse_recursive(node_t * node, node_t * & head){
    if(NULL == node || NULL == node->next){
        head = node;
        return node;
    } else {
        node_t * next_tail = reverse_recursive(node->next, head);
        next_tail->next = node;
        node->next = NULL;
        return node;
    }
}

int main(){
    node_t a = {NULL, 1};
    node_t b = {&a, 2};
    node_t c = {&b, 3};

    node_t * head = &c;
    reverse_recursive(head, head);
    while(head){
        printf("%d,", head->data);
        head = head->next;
    }

    return 0;
}
