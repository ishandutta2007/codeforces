#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int a[MAXN], n, k;

int main() {
  string s; cin >> n >> k >> s;
  for (int i = 0; i < n; ++i) {
    a[i + 1] = a[i] + (s[i] == '0');
  }
  int mx = n;
  for (int i = 1; i <= n; ++i) if (s[i - 1] == '0') {
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r - 1) >> 1;
      int x = max(1, i - m), y = min(n, i + m);
      if (a[y] - a[x - 1] >= k + 1) r = m;
      else l = m + 1;
    }
    mx = min(mx, l);
  }
  cout << mx << endl;
  return 0;
}