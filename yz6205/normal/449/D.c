#include <stdio.h>

#define B 20
#define W 1048576
#define MOD 1000000007

int cnt[W];
int bcnt[W];
int pow2[W];
int n;

int main() 
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i) 
  {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }

  for (int i=0; i<B; ++i)
    for (int j=0; j<W; ++j) if (j & (1 << i))
      cnt[j ^ (1 << i)] += cnt[j];

  bcnt[0] = 0;
  for (int i=1; i<W; ++i)
    bcnt[i] = bcnt[i >> 1] + (i & 1);
  pow2[0] = 0;
  for (int i=0; i<n; ++i)
    pow2[i + 1] = (pow2[i] * 2 + 1) % MOD;

  int ans = 0;
  for (int i=0; i<W; ++i)
  {
    ans += ((bcnt[i] & 1) ? -1 : 1) * pow2[cnt[i]];
    ans = (ans % MOD + MOD) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}