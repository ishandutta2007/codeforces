#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

struct Type {
  bool error;
  int pcnt;

  Type(bool _error = true, int _pcnt = -1) : error(_error), pcnt(_pcnt) {}
};

map<string, Type> types;
Type getType(const char *str) {
  int del = 0, add = 0;
  string name = "";
  for (int i = 0; str[i]; i++)
    if (str[i] == '&') del++;
    else if (str[i] == '*') add++;
    else name += str[i];

  if (!types.count(name)) return Type(true);

  Type cur = types[name];
  if (cur.error) return Type(true);

  assert(cur.pcnt >= 0);
  for (int i = 0; i < add; i++)
    if (++cur.pcnt < 0) return Type(true);
  for (int i = 0; i < del; i++)
    if (--cur.pcnt < 0) return Type(true);
  return cur;
}

char op[1024];
char n1[1024];
char n2[1024];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    types.clear();
    types.insert(mp("void", Type(false, 0)));
    types.insert(mp("errtype", Type(true)));

    for (int i = 0; i < n; i++) {
      scanf(" %s %s", op, n1);
      Type first = getType(n1);

      if (!strcmp(op, "typedef")) {
        scanf(" %s", n2);
        types.erase(n2);
        types.insert(mp(n2, first));
      } else if (!strcmp(op, "typeof")) {
        if (first.error) printf("errtype");
        else {
          printf("void");
          for (int i = 0; i < first.pcnt; i++)
            printf("*");
        }
        printf("\n");
      } else
        assert(false);
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}