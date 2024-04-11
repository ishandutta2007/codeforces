#include <cstdio>
#include <algorithm>
#define ll long long
const int N=100005, lim=400;
int n, a[N], b[N];
int mx=1;
void calc(int d)
{
	int ret=0;
	for(int i=1; i<=n; ++i) b[i]=a[i]-d*i;
	std::sort(b+1, b+n+1);
	for(int l=1, r; l<=n; l=r+1)
	{
		r=l;
		while(r<n&&b[r+1]==b[l]) ++r;
		ret=std::max(ret, r-l+1);
	}
	mx=std::max(ret, mx);
}
int stk[N], top;
void calc1(int x)
{
	top=0;
	for(int i=std::max(1, x-lim); i<x; ++i) if((a[i]-a[x])%(x-i)==0)
		stk[++top]=(a[i]-a[x])/(x-i);
	std::sort(stk+1, stk+top+1);
	int ret=0;
	for(int l=1, r; l<=top; l=r+1)
	{
		r=l;
		while(r<top&&stk[r+1]==stk[l]) ++r;
		ret=std::max(ret, r-l+1);
	}
	mx=std::max(mx, ret+1);
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=-lim; i<=lim; ++i) calc(i);
	for(int i=1; i<=n; ++i) calc1(i);
	printf("%lld\n", n-mx);
	return 0;
}