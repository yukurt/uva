#include <stdio.h>
#include <list>
#include <map>

struct edge {
  int a;
  int b;
};

int main() {
  std::list<edge> edges;
  std::map<int, int> colors;
  edge e;
  int i, n, l, a, b, color_a, color_b, violation_found;
  std::list<edge>::iterator e_itr;

  while (1) {
    scanf("%d", &n);

    if (n == 0) {
      break;
    }

    scanf("%d", &l);

    edges.clear();
    colors.clear();

    for (i = 0; i < l; ++i) {
      scanf("%d %d", &a, &b);
      e.a = a;
      e.b = b;
      edges.push_back(e);
    }

    colors[edges.begin()->a] = 1;
    colors[edges.begin()->b] = 2;
    edges.erase(edges.begin());

    violation_found = false;
    while (!edges.empty()) {
      e_itr = edges.begin();
      while (e_itr != edges.end()) {
        color_a = colors[e_itr->a];
        color_b = colors[e_itr->b];

        if (color_a) {
          if (color_b) {
            if (color_a == color_b) {
              violation_found = true;
              break;
            }
          }
          else {
            color_b = color_a == 1 ? 2 : 1;
            colors[e_itr->b] = color_b;
          }
        }
        else {
          if (color_b) {
            color_a = color_b == 1 ? 2 : 1;
            colors[e_itr->a] = color_a;
          }
          else {
            ++e_itr;
            continue;
          }
        }
        e_itr = edges.erase(e_itr);
      }

      if (violation_found) {
        break;
      }
    }

    if (violation_found) {
      printf("NOT BICOLORABLE.\n");
    }
    else {
      printf("BICOLORABLE.\n");
    }

/*
    for (std::list<edge>::iterator i = edges.begin();
      i != edges.end(); ++i
    ) {
      printf("E: %d %d\n", i->a, i->b);
    }
    printf("\n");
*/
  }

  return 0;
}
