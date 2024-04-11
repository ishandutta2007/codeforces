#include <bits/stdc++.h>
typedef long long ll;
const int N = 6e5 + 5, M = 1 << 30;
const ll P = 1e18;
std::map<int, int> cnt;
int n, w[N], fail[N], anc[N], stk[N], top;
ll res; 
char s[N];
struct Big {
  ll a, b;
  inline void operator += (const ll &x) {if ((b += x) >= P) b -= P, ++a;}
  inline void print() {
    if (a) printf("%lld%018lld\n", a, b);
    else printf("%lld\n", b);
  }
  inline int val(int mod) {return (a * (P % mod) + b) % mod;}
} ans;
int main() {
  scanf("%d", &n);
  for (int i = 1, j = 0; i <= n; ++i) {
    scanf("%s%d", s + i, &w[i]);
    s[i] = (s[i] - 'a' + ans.val(26)) % 26 + 'a', w[i] ^= ans.val(M) & (M - 1);
    anc[i - 1] = s[fail[i - 1] + 1] == s[i] ? anc[fail[i - 1]] : fail[i - 1];
    while (j && s[j + 1] != s[i]) j = fail[j];
    if (i > 1 && s[j + 1] == s[i]) ++j;
    fail[i] = j;
    for (int p = i - 1, v; p;)
      if (s[p + 1] == s[i]) p = anc[p];
      else v = w[*std::lower_bound(stk + 1, stk + top + 1, i - p)], (--cnt[v] == 0) ? cnt.erase(v) : 0, res -= v, p = fail[p];
    while (top && w[stk[top]] > w[i]) --top;
    stk[++top] = i;
    if (s[i] == s[1]) ++cnt[w[i]], res += w[i];
    for (auto it = cnt.upper_bound(w[i]), nxt = it; it != cnt.end(); ++it, cnt.erase(nxt), nxt = it) 
      cnt[w[i]] += it->second, res -= 1ll * it->second * (it->first - w[i]);
    ans += res, ans.print();
  }
  return 0;
}