// Samson DeVol, cs344 project5, implement linked list

#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void llist_insert_head(struct node **head, struct node *n){
  n -> next = *head;
  *head = n;
}
struct node *llist_delete_head(struct node **head);
void llist_insert_tail(struct node **head, struct node *n);

void llist_print(struct node *head){
  if (head == NULL){
    printf("[empty]\n");
  }
  struct node *current_node = head;
  while(current_node != NULL){
    printf("%d", current_node -> value);
    if(current_node -> next == NULL){
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
  struct node *new_node;
  new_node = malloc(sizeof(struct node));
  new_node -> value = value;
  new_node -> next = NULL;
  return new_node;
}

void node_free(struct node *n){
  free(n);
}

int main(int argc, char *argv[]){
  char *commands[argc-1];
  struct node *head = NULL;
  for(int i = 1; i < argc; i++){
    if (strcmp("ih", argv[i])){
      int x =atoi(argv[i]);
      struct node *new_head = node_alloc(x);
      llist_insert_head(&head, new_head);
      printf("argv[%d]: %s, argv[%d]: %s\n", i-1, argv[i-1], i, argv[i]);
    }
    commands[i-1] = malloc(strlen(argv[i])+1);
    strcpy(commands[i-1], argv[i]);
    printf("arg[%d]: %s\n", i, commands[i-1]);
  }
  struct node *test_node = node_alloc(2);
  struct node *test_node2 = node_alloc(3);
  
  llist_print(head);
}