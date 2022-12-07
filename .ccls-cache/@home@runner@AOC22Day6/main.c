#include <stdio.h>

int main(void) {

  int numDifferent = 0;
  int pos = 0;
  int charCounters[26];
    for (int i=0; i<26; i++)
        charCounters[i] = 0;

  int num;
  FILE *fptr;
  char ch;

  if ((fptr = fopen("Input.txt", "r")) == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  do {
    ch = fgetc(fptr);

    if (ch != EOF)
        printf("%c", ch);
    
  } while (ch != EOF);

  return 0;
}