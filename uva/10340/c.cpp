#include <string.h>
#include <stdio.h>

int main() {
  const int MAX_SIZE = 100000;
  char line[MAX_SIZE];
  char s[MAX_SIZE];
  char t[MAX_SIZE];
  char *pch;
  int i, j;

  bool got_first_word = false;
  while (fgets(line, MAX_SIZE, stdin)) {
    pch = strtok(line, " \t\n");

    while (pch) {
      if (got_first_word) {
        strcpy(t, pch);

        for (i = 0, j = 0; s[i];) {
          if (t[j]) {
            if (s[i] == t[j]) {
              ++i;
            }

            ++j;
          }
          else {
            break;
          }
        }

        if (i == strlen(s)) {
          printf("Yes\n");
        }
        else {
          printf("No\n");
        }

        got_first_word = false;
      }
      else {
        strcpy(s, pch);
        got_first_word = true;
      }

      pch = strtok(NULL, " \t\n");
    }
  }

  return 0;
}

