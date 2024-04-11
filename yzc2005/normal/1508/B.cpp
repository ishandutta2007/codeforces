#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100005;
int t, n, p[N];
ll k, pw[N]; 
int main() {
  pw[0] = pw[1] = 1; for (int i = 2; i < N; ++i) pw[i] = min(ll(4e18), 1ll * pw[i - 1] * 2);
  for (scanf("%d", &t); t; --t) {
    scanf("%d%lld", &n, &k);
    if (k > pw[n]) {puts("-1"); continue;}
    for (int i = 1, j; i <= n; i = j) {
      for (int x = 1; ; ++x) {
        if (k <= pw[n - i - x + 1]) {
          int cur = i + x;
          for (j = i; j < i + x; ++j) p[j] = --cur;  
          break;
        } else k -= pw[n - i - x + 1];
      }
    }
    for (int i = 1; i <= n; ++i) printf("%d%c", p[i], " \n"[i == n]);
  }
  return 0;
}