#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if (!b) return (void)(x=1,y=0);
    exgcd(b,a%b,x,y);
    ll tmp=x;x=y;y=tmp-a/b*y;
}
ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b,a%b); 
}
inline ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
inline ll mabs(ll x){
    return (x>0?x:-x);
}
inline ll fast_mul(ll a,ll b,ll p){
	ll t=0;a%=p;
	while (b){
		if (b&1LL) t=(t+a)%p;
		b>>=1LL;a=(a+a)%p;
	}
	return t;
}
const int N = 500005, M = N * 2;
int n, m, a[N], b[N], p1[M], p2[M];
ll k, p[N], cnt, ans;
inline ll solve(int X,int Y){
    static ll a[3],b[3];
    int n=2;a[1]=::n,a[2]=::m,b[1]=X,b[2]=Y;
    ll A=a[1],B=b[1];
    ll x,y;
    for (int i=2;i<=n;i++){
        ll G=gcd(A,a[i]);
        if (mabs(b[i]-B)%G) return -1;
        exgcd(A,a[i],x,y);
        x=fast_mul(x%(a[i]/G)+(a[i]/G),((b[i]-B)/G)%(a[i]/G)+a[i]/G,a[i]/G);
        ll mod=lcm(A,a[i]);B=(fast_mul(x,A,mod)+B)%mod;A=mod;
    }
    return B;
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), p1[a[i]] = i;
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]), p2[b[i]] = i;
  ll d = 1ll * n * m / gcd(n, m);
  for (int i = 1; i < M; ++i) if (p1[i] && p2[i]) {
    ll D = solve(p1[i] - 1, p2[i] - 1);
    if (~D) p[++cnt] = D + 1;
  }
  sort(p + 1, p + cnt + 1); ll e = d - cnt;
  assert(e); ll tt = (k - 1) / e; ans = d * tt, k -= tt * e;
  if (!k) return printf("%lld\n", ans), 0;
  p[++cnt] = d + 1;
  for (int i = 1; i <= cnt; ++i) {
    ll x = p[i] - p[i - 1] - 1; 
    if (x >= k) printf("%lld\n", ans + p[i - 1] + k), exit(0);
    else k -= x;
  } 
  return 0; 
}