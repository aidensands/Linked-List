#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;

} Node;

Node *new_node(int data){
    Node *new_node = malloc(sizeof(Node));
    new_node -> data = data;
    return new_node;
}

Node *prepend(Node *head, int v){
    if (head == NULL){
        return new_node(v);
    }
    else{
        Node *temp = head;
        head = new_node(v);
        head -> next = temp;
        temp -> previous = head;
        return head;
    }
}

void print_list(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    
    for (int i = 0; i < 10; i++){
        head = prepend(head, i);
    }

    print_list(head);
    return 0;
}
