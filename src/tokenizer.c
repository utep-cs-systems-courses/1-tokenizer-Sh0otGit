//null char = '\0'

#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Returns 1 (True) if char c is a whitespace character
int space_char(char c){
  if (c == ' ' || c == '\t')
  // tried this, was not working, so tried isspace()
    return 1;
  else
    return 0;
}

//Returns 1 (True) if char c is not a whitespace character
int non_space_char(char c){
  if (!space_char(c))
    return 1;
  else
    return 0;
}


//Returns a pointer to the first char in first word in s.
char *word_start(char *s){
  //printf("word_start\n");
  int i = 0;
  while(*(s+i) != '\0'){
    //printf("%c - ", *(s+i));
    //printf("%d - ", i);
    if (non_space_char(*(s+i))){
      //printf("YES %o\n", *(s+i));
      return (s+i);
    }
    //printf("NO\n");
    i += 1;
  }
  return (s+i);
}

// Returns a pointer to the space after the first word in s.
char *word_terminator(char *s){
  int i = 0;
  while(*(s+i) != '\0'){
    if(space_char(*(s+i))){
      return s+i; 
    }
    i++;
  }
  return s+i;
}


//Counts the number of words in the string.
int count_words(char *s){
  int words = 0;
  char *start = word_start(s);
  while(*start != '\0'){
    if (non_space_char(*start))
      words += 1;
    start = word_terminator(start);
    start = word_start(start);
  }
  return words;
}  

//malloc usage: malloc(num + 1(to add terminator 0)) * sizeof(type of var)

		      
char *copy_str(char *inStr, short len){
  char *copied = malloc((len+1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++){
    copied[i] = inStr[i];
  }
  copied[i] = '\0'; // to terminate
  return copied;
}

//returns a list of all of the tokenized values.
char **tokenize(char* s){
  //printf("start tokenizer\n");
  int word_count = count_words(s);
  char **tokens = malloc((word_count+1) * sizeof(char *));
  //printf("%d\n", tokens);
  char *start = s;
  int i;
  for (i = 0; i < word_count; i++){
    start = word_start(start);

    // get length of word
    char *temp_s = word_start(start);
    char *temp_t = word_terminator(temp_s);
    int length = temp_t - temp_s;
    //printf("length - %d\n", length);

    tokens[i] = copy_str(start, length);
    start = word_terminator(start);
  }
  tokens[i] = 0; // to terminate
  return tokens;
}

//prints all tokens in order.
void print_tokens(char **tokens){
  int i;
  for (i = 0; tokens[i] != 0; i++){
    printf("%d: ", i);
    printf("%s\n", tokens[i]);
  }
}

//deallocates memory previously allocated using malloc
void free_tokens(char **tokens){
  int i;
  for (i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens);
}
