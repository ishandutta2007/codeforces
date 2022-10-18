#include <cstdio>
#include <algorithm>
const int N=1000005, blc=300;
int n, q, bel[N], a[N], to[N], mx[N];
int tag[N];
inline int cbel(int x) { return (x+blc-1)/blc; }
void build(int x)
{
	int l=(x-1)*blc+1, r=std::min(n, x*blc);
	mx[x]=0;
	for(int i=l; i<=r; ++i) a[i]=std::max(0, a[i]-tag[x]), mx[x]=std::max(mx[x], a[i]);
	tag[x]=0;
	for(int i=l; i<=r; ++i)
		to[i]=a[i]<l?a[i]:to[a[i]];
}
inline int rto(int x)
{
	return bel[std::max(0, a[x]-tag[cbel(x)])]==bel[x]?to[x]:std::max(0, a[x]-tag[cbel(x)]);
}
int ask(int x, int y)
{
	while(rto(x)!=rto(y))
	{
		if(x<y) std::swap(x, y);
		x=rto(x);
	}
	while(x!=y)
	{
		if(x<y) std::swap(x, y);
		x=std::max(0, a[x]-tag[cbel(x)]);
	}
	return x;
}
inline void add(int l, int r, int v)
{
	if(bel[l]==bel[r])
	{
		for(int i=l; i<=r; ++i) a[i]=std::max(0, a[i]-v);
		build(bel[l]);
		return;
	}
	for(int i=l; bel[i]==bel[l]; ++i) a[i]=std::max(0, a[i]-v);
	build(bel[l]);
	for(int i=bel[l]+1; i<bel[r]; ++i)
	{
		tag[i]=std::min(n, tag[i]+v);
		if(mx[i]>=(i-1)*blc) build(i);
	}
	for(int i=r; bel[i]==bel[r]; --i) a[i]=std::max(0, a[i]-v);
	build(bel[r]);
}
int main()
{
	scanf("%d%d", &n, &q);
	--n;
	for(int i=1; i<=n; ++i) scanf("%d", a+i), --a[i];
	for(int i=1; i<=n; ++i) bel[i]=cbel(i);
	for(int i=1; i<=bel[n]; ++i) build(i);
	for(int i=1, t, x, y, z; i<=q; ++i)
	{
		scanf("%d%d%d", &t, &x, &y);
		--x, --y;
		if(t==1)
		{
			scanf("%d", &z);
			x=std::max(1, x);
			if(x<=y) add(x, y, z);
		}
		else
		{
			printf("%d\n", ask(x, y)+1);
		}
	}
	return 0;
}