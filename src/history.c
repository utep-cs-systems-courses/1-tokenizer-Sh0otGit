#include "history.h"
#include "tokenizer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//initialize the linked list to keep the history
List* init_history(){
  List *list = malloc(sizeof(List)); //memory for list
  list->root = malloc(sizeof(Item)); // memory for root of list
  list->root->str = "test";
  list->root->id = 0;
  return list;
}

//-> operator: used to access elements in a structure using a pointer var.

/* add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store */
void add_history(List* list, char *str){
  int i = 1;
  Item *temp = list->root;
  while (temp->next != NULL){ // go to end of list
    temp = temp->next;
    i += 1;
  }
  temp->next = malloc(sizeof(Item));
  //populate history with string
  
  temp->next->str = copy_str(str, strlen(str));
  temp->next->id = i;
}

/*Retrieve the string stored in the node where Item->Id == id.
  List* list - the linked list
  int id - the id of the Item to find */
char *get_history(List *list, int id){
  //printf("get_history, %s, %d\n", list, id);
  Item *temp = list->root;
  while(temp->next != NULL){
    printf("LOL %d, %d", temp->id, id);
    if (temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return temp->str;
}

//print the entire contents of the list.
void print_history(List *list){
  Item *temp = list->root;
  printf("Token History:\n");
  while(temp != NULL){
    printf("- %d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  free(list);
}
