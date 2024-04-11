#include <bits/stdc++.h>
using namespace std;
int t, n;
const int N = 300005;
char s[N];
inline bool judge() {
  bool flag = 1, qwq = 1;
  for (int i = 0; i < n; ++i) {
    flag &= s[i] != '<';
    qwq &= s[i] != '>'; 
  }
  return flag || qwq;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s);
    if (judge()) {
      printf("%d\n", n);
    } else {
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        int x = (i + n - 1) % n, y = i;
        ans += s[x] == '-' || s[y] == '-'; 
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}