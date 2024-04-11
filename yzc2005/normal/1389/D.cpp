#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
inline void ckmax(int &a, int b) { if (a < b) a = b; }
int n, k, l1, r1, l2, r2;
signed main() {
  int T; scanf("%lld", &T); while (T--) {
    scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &l1, &r1, &l2, &r2);
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    int len1 = r1 - l1, len2 = r2 - l2;
    if (l2 > r1) {
      int all = r2 - l1, tmp = l2 - r1, cost = all + tmp;
      if (k <= all * n) {
        int ans = cost * (k / all) + (k % all ? tmp + (k % all) : 0);
        for (int i = 1; i <= k / all; ++i)  
          ans = min(ans, cost * i + (k - all * i) * 2); 
        printf("%lld\n", ans);
      } else {
        int ans = cost * n + (k - all * n) * 2;
        for (int i = 1; i < n; ++i)
          ans = min(ans, cost * i + (k - all * i) * 2);
        printf("%lld\n", ans); 
      }
    } else if (r2 <= r1) {
      if (k <= len2 * n) {
        puts("0");
      } else if (k <= len1 * n) {
        printf("%lld\n", k - len2 * n);
      } else {
        printf("%lld\n", (len1 - len2) * n + (k - len1 * n) * 2);
      }      
    } else {
      int sec = r1 - l2, all = r2 - l1;
      if (k <= sec * n) {
        puts("0");
      } else if (k <= all * n) {
        printf("%lld\n", k - sec * n);
      } else {
        printf("%lld\n", (all - sec) * n + (k - all * n) * 2);
      } 
    }
  }
}