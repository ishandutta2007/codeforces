#include <cstdio>
#include <algorithm>
#define ll long long
const int N=100005;
int n, q, l0[N], a[N];
ll rsu[N], lg[N], s[N][25], mns[N][25], mxs[N][25];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), a[i]-=x;
	for(int i=1; i<=n; ++i)
	{
		rsu[i]=a[i]+rsu[i-1];
	}
	for(int i=1; i<=n; ++i) s[i][0]=mns[i][0]=mxs[i][0]=-a[i];
	for(int i=2; i<=n; i<<=1) ++lg[i];
	for(int i=1; i<=n; ++i) lg[i]+=lg[i-1];
//	for(int i=1; i<=n; ++i) printf("s %d %d %lld\n", i, -a[i], rsu[i]);
	for(int l=1; (1<<l)<=n; ++l) for(int i=1; i+(1<<l)-1<=n; ++i)
	{
		int j=i+(1<<(l-1));
		s[i][l]=s[i][l-1]+s[j][l-1];
		mns[i][l]=std::min(mns[i][l-1], mns[j][l-1]+s[i][l-1]);
		mxs[i][l]=std::max(mxs[i][l-1], mxs[j][l-1]+s[i][l-1]);
	}
	for(int i=1, l, r; i<=q; ++i)
	{
		scanf("%d%d", &l, &r);
		int le=r-l+1;
		le=lg[le];
//		printf("fa %d %lld %d %lld %lld\n", le, mns[l][le], r-(1<<le)+1, rsu[l-1]-rsu[r-(1<<le)], mns[r-(1<<le)+1][le]);
		if(rsu[r]!=rsu[l-1]||std::min(mns[l][le], rsu[l-1]-rsu[r-(1<<le)]+mns[r-(1<<le)+1][le])<0) puts("-1");
		else printf("%lld\n", std::max(mxs[l][le], rsu[l-1]-rsu[r-(1<<le)]+mxs[r-(1<<le)+1][le]));
	}
	return 0;
}