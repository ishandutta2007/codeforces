#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, nxt[N * 2], last[N];
bool vis[N * 2];
int main() {
  scanf("%d", &n);
  if (n & 1) {
    puts("Second");
    fflush(stdout);
    auto rev = [&](int x) {
      return x > n ? x - n : x + n;
    };
    for (int i = 1; i <= n * 2; ++i) {
      int x;
      scanf("%d", &x);
      if (last[x]) {
        nxt[last[x]] = rev(i);
        nxt[i] = rev(last[x]);
      } 
      last[x] = i;
    }
    for (int i = 1; i <= n * 2; ++i) {
      int u = i;
      while (!vis[u] && !vis[rev(u)]) {
        vis[u] = 1;
        u = nxt[u];
      }
    }
    int sum = 0;
    for (int i = 1; i <= n * 2; ++i) {
      sum = (sum + vis[i] * i) % (n * 2);
    }
    if (sum == 0) {
      for (int i = 1; i <= n * 2; ++i) {
        if (vis[i]) {
          printf("%d ", i);
        }
      }
    } else {
      for (int i = 1; i <= n * 2; ++i) {
        if (!vis[i]) {
          printf("%d ", i);
        }
      }
    }
    fflush(stdout);
  } else {
    puts("First");
    fflush(stdout);
    for (int i = 1; i <= n * 2; ++i) {
      printf("%d ", i % n + 1);
    }
  }
  return 0;
}