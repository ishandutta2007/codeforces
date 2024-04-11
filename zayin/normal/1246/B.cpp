#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

const LL inf=1e11;

int n,m;

LL a[maxn];

LL y[maxn],e[maxn];
bool noprime[maxn];
LL p[maxn],pnum;

map<int,int> cnt;

void predo()	{
	for (int i=2;i<maxn;++i)	{
		if (!noprime[i])	{
			p[pnum++]=i;
			y[i]=i;
		}
		for (int j=0;j<pnum&&i*p[j]<maxn;++j)	{
			int k=i*p[j];
			y[k]=p[j];
			noprime[k]=1;
			if (i%p[j]==0)	
				break;
		}
	}
}

int main()	{
	scanf("%d%d",&n,&m);
	predo();
	
	LL ans=0;
	for (int i=1;i<=n;++i)	{
		scanf("%lld",a+i);
		LL A=a[i],c=1,d=1;
		while (A>1)	{
			int p=y[A],e=0;
			while (A%p==0) A/=p,++e;
			e%=m;
			for (int j=0;j<e;++j) c*=p;
			
			if (e)
				for (int j=m;j>e;--j) {
					d*=p;
					if (d>inf)
						d=0;
				}
		}
		
		if (d)
			ans+=cnt[d];
		++cnt[c];
	}
	printf("%lld\n",ans);
	return 0;
}