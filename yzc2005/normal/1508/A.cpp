#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int t, n;
char a[N], b[N], c[N], d[N];
int cnt[N];
bool flag;
inline void work(char *s, char *t) {
int cur, c1[2] = {0, 0}, c2[2] = {0, 0};
for (int i = 1; i <= 2 * n; ++i) c1[s[i] - 48]++, c2[t[i] - 48]++;
int p = (c1[0] >= n) ? 0 : 1, q = (c2[0] >= n) ? 0 : 1;
if (p != q) return; flag = 1;
int a = 0; cur = 0;
memset(cnt + 1, 0, 16 * n);
for (int i = 1; i <= 2 * n; ++i)
if (s[i] == 48 + p) cnt[++a] = cur, cur = 0;
else ++cur;
cnt[++a] = max(0, cur);
int b = 0; cur = 0;
for (int i = 1; i <= 2 * n; ++i)
if (t[i] == 48 + p) ++b, cnt[b] = max(cnt[b], cur), cur = 0;
else ++cur;
++b, cnt[b] = max(cnt[b], cur); a = max(a, b);
for (int i = 1; i <= a; ++i) {
while (cnt[i]--) putchar(48 + (p ^ 1));
if (i != a) putchar(48 + p);
}
puts("");
}
int main() {
for (scanf("%d", &t); t; --t) {
scanf("%d%s%s%s", &n, a + 1, b + 1, c + 1);
flag = 0; work(a, b);
if (!flag) work(b, c);
if (!flag) work(a, c);
}
return 0;
}