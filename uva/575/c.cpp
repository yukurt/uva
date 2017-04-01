#include <stdio.h>
#include <string.h>

int main()
{
  const int MAX_SIZE = 1000;
  char line[MAX_SIZE];
  const char s[10] = " \t\n";
  char *token, c;
  int len, i, j;
  int x;

  while (fgets(line, MAX_SIZE, stdin)) {
    token = strtok(line, s);

    if (!strcmp(token, "0")) {
      break;
    }

    x = 0;
    len = strlen(token);
    for (i = 0; i < len; ++i) {
      c = token[i];

      if (c == '0') {
        j = 0;
      }
      else {
        if (c == '1') {
          j = 1;
        }
        else {
          j = 2;
        }
      }

      x += j * ((2 << (len - i - 1)) - 1);
    }

    printf("%d\n", x);
  }

  return 0;
}
