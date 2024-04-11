#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
int t, n, m;
char s[55];
bool cnt[2];
int main() {
  for (read(t); t; --t) {
    read(n);
    memset(cnt, 0, sizeof(cnt));
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      m = strlen(s);
      tot += (m & 1);
      for (int j = 0; j < m; ++j) {
        cnt[s[j] - '0'] ^= 1;
      }
    }
    printf("%d\n", n - max(0, (cnt[0] | cnt[1]) - tot));
  }
  return 0;
}