#include <algorithm>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100, K = 60;
const ll INF = 1e18;

int n, b[N];
ll a[N], ans;
pll c[N];
int mn_l[N], mx_l[N];
int mn_r[N], mx_r[N];

int mn_mn_cnt[K], mn_mx_cnt[K];
int mx_mn_cnt[K], mx_mx_cnt[K];

int fmin(int i, int j) { return (a[i] < a[j] ? i : j); }
int fmax(int i, int j) { return (a[i] > a[j] ? i : j); }
void solve(int l, int r) {
  if (l == r) {
    ans++;
    return;
  }
  int m = (l + r) >> 1;
  solve(l, m);
  solve(m + 1, r);
  for (int i = l; i <= m; i++)
    mn_l[i] = mx_l[i] = i;
  for (int i = m + 1; i <= r; i++)
    mn_r[i] = mx_r[i] = i;
  for (int i = m - 1; i >= l; i--)
    mn_l[i] = fmin(mn_l[i], mn_l[i + 1]), mx_l[i] = fmax(mx_l[i], mx_l[i + 1]);
  for (int i = m + 2; i <= r; i++)
    mn_r[i] = fmin(mn_r[i], mn_r[i - 1]), mx_r[i] = fmax(mx_r[i], mx_r[i - 1]);
  for (int i = 0; i < K; i++)
    mn_mn_cnt[i] = mn_mx_cnt[i] = mx_mn_cnt[i] = mx_mx_cnt[i] = 0;
  for (int i = l, mn_p = r, mx_p = r; i <= m; i++) {
    while (m + 1 <= mn_p && a[mn_l[i]] > a[mn_r[mn_p]])
      mn_mx_cnt[b[mx_r[mn_p]]]++, mn_mn_cnt[b[mn_r[mn_p]]]++, mn_p--;
    while (m + 1 <= mx_p && a[mx_l[i]] < a[mx_r[mx_p]])
      mx_mx_cnt[b[mx_r[mx_p]]]++, mx_mn_cnt[b[mn_r[mx_p]]]++, mx_p--;
    if (b[mn_l[i]] == b[mx_l[i]])
      ans += min(mn_p, mx_p) - m;
    ans += max(0, mx_mx_cnt[b[mn_l[i]]] - mn_mx_cnt[b[mn_l[i]]]);
    ans += max(0, mn_mn_cnt[b[mx_l[i]]] - mx_mn_cnt[b[mx_l[i]]]);
  }

  for (int i = r, mn_p = l, mx_p = l; i >= m + 1; i--) {
    while (mn_p <= m && a[mn_r[i]] > a[mn_l[mn_p]])
      mn_p++;
    while (mx_p <= m && a[mx_r[i]] < a[mx_l[mx_p]])
      mx_p++;
    if (b[mn_r[i]] == b[mx_r[i]])
      ans += m - max(mn_p, mx_p) + 1;
  }
}
void solve() {
  scanf("%d", &n);
  // cerr << n << endl;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    // a[i] = rand() % 10;
    // cerr << a[i] << " ";
    b[i] = __builtin_popcountll(a[i]);
  }
  // cerr << endl;
  // int kek = 0;
  // for (int i = 1; i <= n; i++) {
  //   ll mn = INF, mx = -INF;
  //   for (int j = i; j <= n; j++) {
  //     mn = min(mn, a[j]);
  //     mx = max(mx, a[j]);
  //     if(__builtin_popcountll(mn) == __builtin_popcountll(mx))
  //       kek++;
  //   }
  // }

  for (int i = 1; i <= n; i++)
    c[i] = {a[i], (ll)i};
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(c + 1, c + n + 1, mp(a[i], (ll)i)) - c;
  solve(1, n);

  // cerr << kek << " " << ans << endl;
  printf("%lld\n", ans);
}
int main() {
  srand(time(0));
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}