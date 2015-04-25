#include <stdio.h>

#define MAX_LEN 70

int main() {

  int c = 0;
  
  int wordsLen[MAX_LEN];
  for (int i = 0; i < MAX_LEN; ++i) {
    wordsLen[i] = 0;
  }

  int currentLen = 0;

  while ((c = getchar()) != EOF) {

    if (c != ' ' && c != '\n' && c != '\t') {
      ++currentLen;
    } else if (currentLen > 0 && currentLen <= MAX_LEN) {
      ++wordsLen[currentLen - 1];
      currentLen = 0;
    }
  }

  if (currentLen > 0 && currentLen <= MAX_LEN) { // in case EOF
                                                 // after last word
    ++wordsLen[currentLen - 1];
  }

  int max = wordsLen[0];

  for (int i = 1; i < MAX_LEN; ++i) {
    if (wordsLen[i] <= max) { continue; }

    max = wordsLen[i];
  }

  printf("Max count: %d\n", max);

  for (int i = max; i > 0; --i) {

    for (int j = 0; j < MAX_LEN; ++j) {

      if (wordsLen[j] >= i) {
        putchar('#');
      } else {
        putchar(' ');
      }
    }
    
    putchar('\n');
  }

  return 0;
}
