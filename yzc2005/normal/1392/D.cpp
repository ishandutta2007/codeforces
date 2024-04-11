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
const int N = 666666;
int t, n, dp[N];
char s[N];
int main() {
  for (read(t); t; --t) {
    scanf("%d%s", &n, s + 1);
    s[n + 1] = s[1], s[n + 2] = s[2], s[n + 3] = s[3];
    int ans = 1e9;
    for (int i = 1; i <= 4; ++i) {
      auto work = [&](int st) {
        dp[st - 1] = 0;
        dp[st] = 1e9;
        for (int i = st + 1; i <= st + n - 1; ++i) {
          int x1 = dp[i - 2] + (s[i - 1] != 'R') + (s[i] != 'L');
          int x2 = i > st + 1 ? dp[i - 3] + (s[i - 2] != 'R') + (s[i] != 'L') : 1e9;
          int x3 = i > st + 2 ? dp[i - 4] + (s[i - 3] != 'R') + (s[i - 1] != 'L') + (s[i - 2] != 'R') + (s[i] != 'L'): 1e9;
          dp[i] = min(x1, min(x2, x3));
        }
      }; work(i);
      ans = min(ans, dp[i + n - 1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}