#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int T,nr,ng,nb,r[N],g[N],b[N];

ll ans;

ll calc(int a,int b,int c)
{
	return 1ll*(a-b)*(a-b)+1ll*(b-c)*(b-c)+1ll*(c-a)*(c-a);
}

ll solve(int *a,int *b,int *c,int na,int nb,int nc)
{
	ll ret=3e18;
	for(int i=1;i<=nb;i++)
	{
		int y=b[i];
		int x,z;
		int px=upper_bound(a,a+na+2,y)-a;
		px--;
		if(!px)
			continue;
		x=a[px];
		int pz=lower_bound(c,c+nc+2,y)-c;
		if(pz==nc+1)
			continue;
		z=c[pz];
		ret=min(ret,calc(x,y,z));
	}
	for(int i=1;i<=nb;i++)
	{
		int y=b[i];
		int x,z;
		int px=upper_bound(c,c+nc+2,y)-c;
		px--;
		if(!px)
			continue;
		x=c[px];
		int pz=lower_bound(a,a+na+2,y)-a;
		if(pz==na+1)
			continue;
		z=a[pz];
		ret=min(ret,calc(x,y,z));
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&nr,&ng,&nb);
		for(int i=1;i<=nr;i++)
			scanf("%d",&r[i]);
		r[nr+1]=1e9+1;
		for(int i=1;i<=ng;i++)
			scanf("%d",&g[i]);
		g[ng+1]=1e9+1;
		for(int i=1;i<=nb;i++)
			scanf("%d",&b[i]);
		b[nb+1]=1e9+1;
		sort(r+1,r+nr+1);
		sort(g+1,g+ng+1);
		sort(b+1,b+nb+1);
		ans=3e18;
		ans=min(ans,solve(r,g,b,nr,ng,nb));
		ans=min(ans,solve(g,b,r,ng,nb,nr));
		ans=min(ans,solve(b,r,g,nb,nr,ng));
		printf("%lld\n",ans);
	}
}