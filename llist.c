// Samson DeVol, cs344 project5, implement linked list

#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

void llist_insert_head(struct node **head, struct node *n){
  // make new head point to old head 
  n -> next = *head;
  // make head the new head
  *head = n;
}

struct node *llist_delete_head(struct node **head){
  // check for null head
  if (*head == NULL){
    return *head;
  }
  // create current node
  struct node *current_node = *head;
  // set head to next node
  *head = current_node -> next;
  // free the current head
  node_free(current_node);
  return *head;
}

void llist_insert_tail(struct node **head, struct node *n){
  // create current node
  struct node *current_node = *head;
  // check if head is null, and insert new node as head if true
  if (*head == NULL){
    llist_insert_head(head, n);
  } else {
    // iterate through nodes
    while(current_node != NULL){
      // if last node in llist, insert new node as next
      if(current_node -> next == NULL){
        current_node -> next = n;
        break;
      } else {
        current_node = current_node -> next;
      }
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
    if (current_node -> next == NULL){
      printf("\n");
      break;
    } else{
      printf(" -> ");
      current_node = current_node -> next;
    }
  }
}

void llist_free(struct node **head){
  // create current node and node to be freed
  struct node *current_node = *head;
  struct node *free_node = current_node;
  // iterate through all nodes
  while(current_node != NULL){
    // set node to be freed to current node
    free_node = current_node;
    // set current node to net
    current_node = current_node -> next;
    // free the node
    node_free(free_node);
  }
  // set the head to NULL
  *head = NULL;
}

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
  free(n);
}

int main(int argc, char *argv[]){
  // set initial head as NULL
  struct node *head = NULL;
  // parse command line arguments
  for(int i = 1; i < argc; i++){
    if (strcmp("ih", argv[i]) == 0){
      int x = atoi(argv[i+1]);
      struct node *new_head = node_alloc(x);
      llist_insert_head(&head, new_head);
      i++;
    } else if (strcmp("it", argv[i]) == 0){
      int x = atoi(argv[i+1]);
      struct node *new_tail = node_alloc(x);
      llist_insert_tail(&head, new_tail);
      i++;
    } else if (strcmp("dh", argv[i]) == 0){
      llist_delete_head(&head);
    } else if (strcmp("p", argv[i]) == 0){
      llist_print(head);
    } else if (strcmp("f", argv[i]) == 0){
      llist_free(&head);
    } else{
      printf("Uh oh, do you know what you're doing?\nAcceptable commands are: ih (int), it (int), dh, p, f\n");
    }
  }
}
