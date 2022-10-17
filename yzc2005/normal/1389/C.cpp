#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
inline void ckmax(int &a, int b) { if (a < b) a = b; }
int n;
char s[N];
int main() {
  int T; scanf("%d", &T); while (T--) {
    scanf("%s", s + 1); n = strlen(s + 1);
    int ans = 0;
    for (int i = 0; i <= 9; ++i)
      for (int j = 0; j <= 9; ++j) {
        int res = 0, cur = i;
        for (int k = 1; k <= n; ++k) 
          if (s[k] - '0' == cur) 
            ++res, cur = cur == i ? j : i;
        ckmax(ans, res - ((res & 1) & (i != j)));
      }
    printf("%d\n", n - ans);
  }
  return 0;
}