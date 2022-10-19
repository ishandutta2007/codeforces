#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int T, n, p[N * 2], pre[N * 2];
bool f[N];
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d", &n);
    memset(f, 0, sizeof(f)); f[0] = 1;
    int lst = 1;
    auto update = [&](int x) {
        for (int i = n; i >= x; --i)
          f[i] |= f[i - x];
    }; 
    for (int i = 1; i <= 2 * n; ++i) {
      scanf("%d", &p[i]);
      pre[i] = max(pre[i - 1], p[i]);
      if (p[i] != pre[i]) continue;
      update(i - lst), lst = i;
    }
    update(2 * n + 1 - lst);
    puts(f[n] ? "YES" : "NO");
  }
  return 0;
}