// Samson DeVol, cs344 project5, implement linked list

#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void llist_insert_head(struct node **head, struct node *n){
  // make new head point to old head 
  n -> next = *head;
  // make head the new head
  *head = n;
}

struct node *llist_delete_head(struct node **head){
  *head = (*head) -> next;
  return *head;
}

void llist_insert_tail(struct node **head, struct node *n){
  struct node *current_node = *head;
  while(current_node -> next != NULL){
    if(current_node -> next -> next == NULL){
      current_node -> next -> next = n;
      break;
    }
    else{
      current_node = current_node -> next;
    }
  }
}

void llist_print(struct node *head){
  // check if linked list is empty
  if (head == NULL){
    printf("[empty]\n");
  }

  // move through the linked list, printing each value
  struct node *current_node = head;
  while(current_node != NULL){
    printf("%d", current_node -> value);
    if(current_node -> next == NULL){
      printf("\n");
      break;
    }
    else{
      printf(" -> ");
      current_node = current_node -> next;
    }
  }
}

void llist_free(struct node **head);

struct node *node_alloc(int value){
  // make new node and allocate memory
  struct node *new_node;
  new_node = malloc(sizeof(struct node));
  // set new node value = value, and next = null
  new_node -> value = value;
  new_node -> next = NULL;
  return new_node;
}

void node_free(struct node *n){
  // free node n
  free(n);
}

int main(int argc, char *argv[]){

  struct node *head = NULL;
  for(int i = 1; i < argc; i++){
    printf("For argv[%d]: %s\n", i, argv[i]);
    if (strcmp("ih", argv[i]) == 0){
      int x = atoi(argv[i+1]);
      struct node *new_head = node_alloc(x);
      llist_insert_head(&head, new_head);
      printf("After insert head: ");
      llist_print(head); 
    }
    else if (strcmp("it", argv[i]) == 0){
      int x = atoi(argv[i+1]);
      struct node *new_tail = node_alloc(x);
      llist_insert_tail(&head, new_tail);
      printf("After insert tail: ");
      llist_print(head);
    }

  }
  llist_delete_head(&head);
  llist_delete_head(&head);
  
  llist_print(head);
}