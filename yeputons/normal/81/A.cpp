#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

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

void rem(vi &pr, vi &ne, vb &use, int id) {
  assert(use[id]);
  if (pr[id] >= 0)
    ne[pr[id]] = ne[id];

  if (ne[id] < pr.size())
    pr[ne[id]] = pr[id];
  use[id] = false;
}

const int MAXL = 2e5;
char buf[MAXL + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", buf) >= 1) {
    int n = strlen(buf);
    vi pr(n), ne(n);
    vb use(n, true);
    for (int i = 0; buf[i]; i++) {
      pr[i] = i - 1, ne[i] = i + 1;
    }

    queue<int> q;
    for (int i = 0; i + 1 < n; i++)
      q.push(i);

    while (!q.empty()) {
      int a = q.front();
      q.pop();
      if (ne[a] >= n) continue;
      if (!use[a] || !use[ne[a]]) continue;

      if (buf[a] == buf[ne[a]]) {
        rem(pr, ne, use, ne[a]);
        rem(pr, ne, use, a);
        a = pr[a];
        if (a >= 0 && ne[a] < n)
          q.push(a);
      }
    }
    for (int i = 0; i < n; i++)
      if (use[i])
        printf("%c", buf[i]);
    printf("\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}