/*
 * A: Building A Simple UI
 * Objective: Create a simple functioning user interface, with an indicator that echos when sent.
 */

#include "tokenizer.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>

int max_size = 100;

int main(){
  
  //Lesson 1: Learning what a buffer is and how to use it in C.
  char initial[max_size];
  char input[max_size];
  List *history = init_history();
  while(1){
    printf("Welcome to Lab 1: Tokenizer! Please enter one of the following commands.\n - Type '0' to exit.\n - Type '1' to input a sentence.\n - Type '2' to view history.\n - Type '!' followed by a number to view a certain history.\n");
    printf("$ ");
    fgets(initial, max_size, stdin);

    // Stop Program.
    if (initial[0] == '0'){
      printf("Stopping program...\n");
      return 0;
      
    }
    else if (initial[0] == '1'){
  // Evaluate input
      printf("Type your sentence...\n");
      printf("$ ");
      fgets(input, max_size, stdin);
      printf("You typed: %s\n", input);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history, input);
      free_tokens(tokens);
  
    }
    else if (initial[0] == '2'){
      print_history(history);
    }
    else if (initial[0] == '!'){
      int num = atoi(&initial[1]);
      char *h = get_history(history, num); // atoi() parsed char to int
      char **tokens = tokenize(h);
      printf("History found: %s\n", h);
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else {
      printf("Invalid input, try again.\n");
    }
  }
}
