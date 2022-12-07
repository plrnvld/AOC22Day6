#include <stdio.h>

int numDifferent = 0;
int pos = 0;
int charCounters[26];
const int distinct = 4;
char prevChars[distinct];

int getPos(char c) {
  return (int)c - (int)'a';
}

void addChar(char c) {
  prevChars[pos % distinct] = c;    
  int i = getPos(c);        
  charCounters[i]++;
  if (charCounters[i] == 1)
    numDifferent++;  
}

void removeChar(char c) {
  int i = getPos(c);
  charCounters[i]--;
  if (charCounters[i] == 0)
    numDifferent--;
}  

int main(void) {
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
    if (ch != EOF) {
      if (pos >= distinct)
        removeChar(prevChars[(pos-distinct) % distinct]);
        
      addChar(ch);
      if (numDifferent >= distinct) {
        printf("Start of packet found: %d\n", pos + 1);
        exit(0);
      }
    }
    pos++;
  } while (ch != EOF);

  return 0;
}