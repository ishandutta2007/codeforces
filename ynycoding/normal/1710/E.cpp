#include <cstdio>
#include <functional>
#include <algorithm>
#define ll long long
const int N=400005;
int n, m, a[N], b[N], ca[N], cb[N], f[N], x, y;
ll suma[N], sumb[N], tot;
inline ll calc(int x, int y)
{
	if(ca[x]<y)
	{
		return suma[x]+sumb[y]-tot+1ll*(n-x)*(m-y);
	}
	else
	{
		return 1ll*x*y+1ll*(n-x)*m-(tot-suma[x])+1ll*(m-y)*n-(tot-sumb[y])-(1ll*n*m-tot);
	}
}
inline ll calc1(int x, int y)
{
	if(ca[x]<y)
	{
		return suma[x]+sumb[y]-tot+1ll*(n-x)*(m-y)-(::x>x&&::y>y);
	}
	else
	{
		return 1ll*x*y+1ll*(n-x)*m-(tot-suma[x])+1ll*(m-y)*n-(tot-sumb[y])-(1ll*n*m-tot)-(::x>x&&::y>y);
	}
}
int calc(void)
{
	ll ret=std::max(tot, 1ll*n*m-tot);
	for(int i=1, j=1; i<=n; ++i)
	{
		while(j<m&&calc(i, j+1)>=calc(i, j)) ++j;
		ret=std::max(ret, calc(i, j));
	}
	return ret;
}
int calc1(void)
{
	ll ret=std::max(tot, 1ll*n*m-tot-1);
	for(int i=1, j=1; i<=n; ++i)
	{
		while(j<m&&calc1(i, j+1)>=calc1(i, j)) ++j;
		ret=std::max(ret, calc1(i, j));
	}
	return ret;
}
bool chk(int c)
{
	for(int i=1, j=m; i<=n; ++i)
	{
		while(j&&b[j]+a[i]>c) cb[j]=i-1, --j;
		ca[i]=j;
		if(i==n) while(j) cb[j--]=n;
	}
	for(int i=1; i<=n; ++i) suma[i]=suma[i-1]+ca[i];
	for(int i=1; i<=m; ++i) sumb[i]=sumb[i-1]+cb[i];
	tot=suma[n];
//	printf("f %d\n", calc(2, 2));
	return calc()==calc1();
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=m; ++i) scanf("%d", b+i);
	x=a[1], y=b[1];
	std::sort(a+1, a+n+1);
	std::sort(b+1, b+m+1);
	x=std::lower_bound(a+1, a+n+1, x)-a;
	y=std::lower_bound(b+1, b+m+1, y)-b;
	int l=a[1]+b[1], r=a[x]+b[y];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n", l);
	return 0;
}