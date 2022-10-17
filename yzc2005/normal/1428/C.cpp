#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n;
char s[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cb = 0, ans = n;
    for (int i = n; i; --i) {
      if (s[i] == 'A') {
        if (cb) {
          ans -= 2;
          --cb;
        }
      } else {
        ++cb;
      }
    }
    printf("%d\n", ans - (cb / 2) * 2);
  }
  return 0;
}