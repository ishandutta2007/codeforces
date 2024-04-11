#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[55], ss[55];
const char t[] = {"abacaba"};
bool judge(char *s) {
  for (int i = 0; i < 7; ++i)
    if (s[i] != t[i]) return 0;
  return 1;
}
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%s", &n, s + 1);
    int cnt = 0;
    for (int i = 1; i <= n - 6; ++i)
      cnt += judge(s + i);
    if (cnt == 1) {
      puts("Yes");
      for (int i = 1; i <= n; ++i)
        if (s[i] == '?') s[i] = 'z';
      printf("%s\n", s + 1);
      continue;
    } else if (cnt > 1) {
      puts("No");
      continue;
    }
    bool ok = 0;
    for (int st = 1; st <= n - 6; ++st) {
      bool valid = 1;
      for (int i = 0; i < 7; ++i)
        if (s[i + st] != t[i] && s[i + st] != '?') {
          valid = 0;
          break;
        } 
      if (!valid) continue;
      for (int i = 1; i <= n; ++i) 
        ss[i] = (i >= st && i < st + 7) ? t[i - st] : (s[i] == '?' ? 'z' : s[i]);
      int cnt = 0;
      for (int i = 1; i <= n - 6; ++i)
        cnt += judge(ss + i);
      if (cnt == 1) {
        puts("Yes"); ss[n + 1] = '\0';
        printf("%s\n", ss + 1);
        ok = 1; break;
      }
    }
    if (!ok) puts("No");
  }
  return 0; 
}