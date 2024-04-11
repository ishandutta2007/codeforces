#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 300005
ll n, m, x[MAXN], s[MAXN], p[MAXN], f, idx;
inline ll gcd(ll a, ll b) { while(b!=0) { a%=b, std::swap(a, b); } return a; }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%I64d", x+i);
	for(int i=2; i<=n; ++i) f=gcd(x[i]-x[i-1], f);
	for(int i=1; i<=m; ++i) { scanf("%I64d", p+i); if(f%p[i]==0) { idx=i; break; } }
	if(!idx) return puts("NO"), 0;
	printf("YES\n%I64d %d", x[1], idx);
	return 0;
}