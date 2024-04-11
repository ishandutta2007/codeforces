#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int eprintf(const char* format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define pb push_back
#define mp make_pair
#define TASKNAME ""

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int n;
vvi es; vi pars;

void dfs(int v) {
  for (int i = 0; i < es[v].size(); i++) {
    int b = es[v][i];
    if (pars[b] >= 0) continue;
    pars[b] = v;
    dfs(b);
  }
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  int s1, s2;
  while (scanf("%d%d%d", &n, &s1, &s2) >= 3) {
    s1--, s2--;

    es = vvi(n);
    for (int i = 0; i < n - 1; i++) {
      int a = i, b;
      if (i >= s1) a++;
      scanf("%d", &b), b--;

      es[a].pb(b);
      es[b].pb(a);
    }
    pars = vi(n, -1);
    pars[s2] = 0;
    dfs(s2);

    bool first = true;
    for (int i = 0; i < n; i++) {
      if (i == s2) continue;
      if (!first) printf(" "); first = false;
      printf("%d", pars[i] + 1);
    }
    printf("\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}