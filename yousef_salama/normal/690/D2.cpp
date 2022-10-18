#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000003
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

int fact[700005], inv[700005], factinv[700005];

int main()
{
  int n, c;
  cin >> n >> c;
  fact[1] = inv[1] = factinv[1] = 1;
  fact[0] = inv[0] = factinv[0] = 1;
  for(int i=2;i<=700000;i++)
  {
    fact[i] = (i * 1LL * fact[i - 1]) % mod;
    inv[i] = (mod - (((mod/i)* 1LL * inv[mod%i])%mod))%mod;
    factinv[i] = (inv[i] * 1LL * factinv[i - 1]) % mod;
  }
  int res = 0;
  for(int i=1;i<=n;i++)
  {
    int tmp = (fact[i + c - 1] * 1LL * factinv[i]) % mod;
    tmp = (tmp * 1LL * factinv[c - 1]) % mod;
    res += tmp;
    if(res >= mod)
      res -= mod;
  }
  cout << res;
  return 0;
}