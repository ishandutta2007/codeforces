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
int t, n;
char s[505];
bool ok[30];
int main() {
  for (read(t); t; --t) {
    scanf("%s", s);
    n = strlen(s);
    memset(ok, 0, sizeof(ok));
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] != s[i - 1]) {
        if (cnt & 1) {
          ok[s[i - 1] - 'a'] = 1;
        }
        cnt = 1;
      } else {
        ++cnt;
      }
    }
    if (cnt & 1) {
      ok[s[n - 1] - 'a'] = 1;
    }
    for (int i = 0; i < 26; ++i) {
      if (ok[i]) {
        printf("%c", (char)i + 'a');
      }
    }
    puts("");
  }
  return 0;
}