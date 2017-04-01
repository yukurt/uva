#include <stdio.h>
#include <string.h>

int main() {
  const int MAX_SIZE = 10000;
  char line[MAX_SIZE], word[MAX_SIZE], rword[MAX_SIZE];
  int i, j, k, p;
  bool found_word;
  char c, d;

  while (fgets(line, MAX_SIZE, stdin)) {
    found_word = false;

    for (i = 0; 1; ++i) {
      c = line[i];

      if (!c) {
        if (found_word) {
          word[j] = 0;
          for (k = strlen(word) - 1, p = 0; k >= 0; --k, ++p) {
            rword[p] = word[k];
          }
          rword[p] = 0;
          printf("%s", rword);
        }
        break;
      }

      if (c == ' ' || c == '\t' || c == '\n') {
        if (found_word) {
          word[j] = 0;
          for (k = strlen(word) - 1, p = 0; k >= 0; --k, ++p) {
            rword[p] = word[k];
          }
          rword[p] = 0;
          printf("%s%c", rword, c);
          found_word = false;
        }
        else {
          printf("%c", c);
        }
      }
      else {
        if (found_word) {
          word[j] = c;
          ++j;
        }
        else {
          word[0] = c;
          j = 1;
          found_word = true;
        }
      }
    }
  }

  return 0;
}
