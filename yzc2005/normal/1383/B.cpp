#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, n, a[N];
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d", &n);
    auto work = [&](int k) {
      int x = 0, y = 0;
      for (int i = 1; i <= n; ++i)
        x += a[i] >> k & 1;
      y = n - x;
      if (x % 2 == 0) return 0;
      if ((x + 1) % 4) return 1;
      return y & 1 ? 1 : -1;
    };
    for (int i = 1; i <= n; ++i) 
      scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 30; ~i; --i) 
      if (ans = work(i)) break; 
    if (ans == 1) puts("WIN");
    if (ans == 0) puts("DRAW");
    if (ans == -1) puts("LOSE");
  } 
}