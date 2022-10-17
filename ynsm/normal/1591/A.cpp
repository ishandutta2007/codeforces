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

void solve() {
  int n;
  scanf("%d", &n);
  int cnt = 0, ans = 1;
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x)
      cnt = max(1, cnt + 1), ans += (cnt >= 2 ? 5 : 1);
    else
      cnt = min(-1, cnt - 1), ans = (cnt != -2 ? ans : -inf);
    // cerr << ans << endl;
  }
  if (ans < 0)
    ans = -1;
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}