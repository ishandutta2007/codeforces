#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int t, n, k, c[N];
char s[N];
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    memset(c, -1, k * 4);
    bool flag = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        s[i] -= '0';
        if (~c[i % k] && c[i % k] != s[i]) {
          flag = 0;
          break;
        }
        c[i % k] = s[i];
      }
    }
    if (!flag) {
      puts("NO");
      continue;
    }
    int cnt[2] = {0, 0};
    for (int i = 0; i < k; ++i) {
      if (~c[i]) {
        ++cnt[c[i]];
      }
    }
    if (max(cnt[0], cnt[1]) <= k / 2) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}