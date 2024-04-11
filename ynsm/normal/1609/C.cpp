#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100;

int n, k, a[N], b[N];

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    ll cur = 0, cnt = 0;
    for (int j = i, q = i; j < n; j += k) {
      while (q < j)
        cur += b[a[q]], q += k, cnt++;
      while (q < n && cur + b[a[q]] <= 1)
        cur += b[a[q]], q += k, cnt++;
      if (cur <= 1)
        ans += max(0ll, cnt - 1);
      // cerr << j << " " << q << " " << cur << " " << cnt <<  " " << ans << endl;
      cnt--;
      cur -= b[a[j]];
    }
  }
  for (int i = 0; i < k; i++) {
    ll cur = 0, cnt = 0;
    for (int j = i, q = i; j < n; j += k) {
      while (q < j)
        cur += b[a[q]], q += k, cnt++;
      while (q < n && cur + b[a[q]] <= 0)
        cur += b[a[q]], q += k, cnt++;
      if (cur <= 0)
        ans -= max(0ll, cnt - 1);
      cnt--;
      cur -= b[a[j]];
    }
  }
  printf("%lld\n", ans);
}
int main() {
  for (int i = 2; i < N; i++)
    for (int j = i; j < N; j += i)
      b[j]++;
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}