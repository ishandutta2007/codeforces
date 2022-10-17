#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k, a[N];
ll ans;
int A, B;
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n);
  ans = 0;
  A = B = 0;
  for (int i = 0; a[i] < 0 && i < n; i += k)
    ans += abs(a[i]) * 2, A = max(A, abs(a[i]));
  for (int i = n - 1; a[i] > 0 && i >= 0; i -= k)
    ans += abs(a[i]) * 2, B = max(B, abs(a[i]));
  ans -= max(A, B);
  printf("%lld\n", ans);
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}