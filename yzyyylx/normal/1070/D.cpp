#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long li;

const int maxn = 2e5 + 10;
int n;
li k, a[maxn];

int main(void) {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  li x = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    li tmp = x + a[i];
    if (tmp % k > a[i]) {
      ans += (tmp / k) + 1;
      x = 0;
    } else {
      ans += tmp / k;
      x = tmp % k;
    }
  }
  ans += (x > 0);
  printf("%lld\n", ans);
  
  return 0;
}