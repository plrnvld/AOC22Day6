#include <stdio.h>

int main(void) {

  printf("Hello World\n");

  int num;
  FILE *fptr;
  char ch;

  if ((fptr = fopen("Input.txt", "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  printf("content of this file are \n");

  // Printing what is written in file
  // character by character using loop.
  do {
    ch = fgetc(fptr);

    if (ch != EOF)
        printf("%c", ch);
    
  } while (ch != EOF);

  return 0;
}