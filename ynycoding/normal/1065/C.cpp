#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define ll long long
#define MAXN 200001
using namespace std;
ll n, k, a[MAXN], ans, cur, h, mx, mn=0x7fffffff, sum[MAXN];
void add(int p, ll val) { while(p<MAXN) { sum[p]+=val, p+=lowbit(p); } }
ll query(int p) { ll ret=0; while(p) { ret+=sum[p], p-=lowbit(p); } return ret; }
int main()
{
	scanf("%lld%lld", &n, &k);
	if(n==1) return puts("0"), 0;
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), mx=max(mx, a[i]), mn=min(mn, a[i]), add(1, 1), add((int)a[i]+1, -1);
	for(int i=mx; i>mn;)
	{
		ll cur=0;
		while(cur+query(i)<=k&&i>mn) cur+=query(i), --i;
		++ans;
	}
	printf("%lld", ans);
	return 0;
}