#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], b[N], c[N];
char s[N];
void solve() {
  scanf("%d%s", &n, s + 1);
  int tot = 0;
  memset(a, 0, n + 1 << 2);
  for (int i = 1; i <= n; ++i)
    if (s[i] == '0') c[++tot] = i;
  if (tot & 1) return void(puts("NO"));
  for (int i = 1; i <= tot; ++i) a[c[i]] = !(i & 1);
  int s1 = 0, s2 = 0; tot /= 2;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') a[i] = ++tot <= n / 2;
    b[i] = s[i] == '1' ? a[i] : (1 - a[i]);
    s1 += a[i] ? 1 : -1;
    s2 += b[i] ? 1 : -1;
    if (s1 < 0 || s2 < 0) return void(puts("NO"));
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%c", a[i] ? '(' : ')');
  puts("");
  for (int i = 1; i <= n; ++i) printf("%c", b[i] ? '(' : ')');
  puts("");
} 
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}