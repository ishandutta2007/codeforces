#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e5;

int n;
int cnt[maxn], pri[maxn];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", cnt + i);
    for (int j = 0; j < cnt[i]; ++j) {
      int x;
      scanf("%d", &x);
      pri[i] = max(pri[i], x);
    }
  }
  int tar = *max_element(pri, pri + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (tar - pri[i]) * (long long)cnt[i];
  }
  printf("%lld\n", ans);
  
}