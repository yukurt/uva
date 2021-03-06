#include <stdio.h>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include <ctype.h>

struct pair {
  char character;
  int count;
  friend bool operator>(const pair& a, const pair& b);
};

bool operator>(const pair& a, const pair& b) {
    if (a.count > b.count) {
      return true;
    }

    if (a.count == b.count && a.character < b.character) {
      return true;
    }

    return false;
}

int main() {
  const int MAX_SIZE = 10000;
  char line[MAX_SIZE];
  int n, i, j;
  char c;
  std::map<char, int> imap;
  std::map<char, int>::iterator k;
  std::vector<pair> v;
  std::vector<pair>::iterator w;
  pair p;

  scanf("%d\n", &n);

  for (i = 0; i < n; ++i) {
    fgets(line, MAX_SIZE, stdin);
    for (j = 0; 1; ++j) {
      c = line[j];

      if (line[j] == '\n' || line[j] == 0) {
        break;
      }

      c = toupper(c);

      if ('A' <= c && c <= 'Z') {
        imap[c] += 1;
      }
    }
  }

  for (k = imap.begin(); k != imap.end(); ++k) {
    p.character = k->first;
    p.count = k->second;
    v.push_back(p);
  }

  std::sort(v.begin(), v.end(), std::greater<pair>());

  for (w = v.begin(); w != v.end(); ++w) {
    printf("%c %d\n", w->character, w->count);
  }

  return 0;
}
