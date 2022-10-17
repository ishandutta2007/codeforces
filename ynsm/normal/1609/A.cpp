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

int n;
ll a[N];
ll y, z;
void solve() {
  scanf("%d", &n);
  y = 1, z = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (x % 2 == 0)
      x /= 2, y *= 2;
    a[i] = x;
    // cerr << x << " " << y << endl;
  }
  sort(a, a + n);
  a[n - 1] *= y;
  // cerr << y << endl;
  for (int i = 0; i < n; i++)
    z += a[i];
  printf("%lld\n", z);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}