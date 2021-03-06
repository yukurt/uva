#include <stdio.h>
#include <stack>

int main() {
  int n;
  const int MAX_SIZE = 100000;
  char line[MAX_SIZE];

  fgets(line, MAX_SIZE, stdin);
  sscanf(line, "%d", &n);

  for (int i = 0; i < n; ++i) {
    fgets(line, MAX_SIZE, stdin);
//    printf("B%sE\n", line);

//    continue;

    std::stack<int> ops;
    for (int j = 0; 1; ++j) {
      char op = line[j];

      if (op == '\n' || op == 0) {
        if (ops.empty()) {
          printf("Yes\n");
        }
        else {
          printf("No\n");
        }

        break;
      }

      if (op == '(' || op == '[') {
        ops.push(op);
      }
      else if (op == ')' || op == ']') {
        if (op == ')') {
          if (ops.empty()) {
            printf("No\n");
            break;
          }
          else {
            if (ops.top() == '(') {
              ops.pop();
            }
            else {
              printf("No\n");
              break;
            }
          }
        }
        else {
          if (ops.empty()) {
            printf("No\n");
            break;
          }
          else {
            if (ops.top() == '[') {
              ops.pop();
            }
            else {
              printf("No\n");
              break;
            }
          }
        }
      }
    }
  }

  return 0;
}
