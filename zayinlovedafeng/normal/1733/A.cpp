#include <bits/stdc++.h>
#define maxn 105
using namespace std;
typedef long long LL;

int n, m;
LL a[maxn];

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) a[i] = 0;
    for (int i = 0; i < n; ++i) {
      LL x;
      cin >> x;
      a[i % m] = max(a[i % m], x);
    }
    LL ans = 0;
    for (int i = 0; i < m; ++i) ans += a[i];
    cout << ans << endl;
  }
  return 0;
}