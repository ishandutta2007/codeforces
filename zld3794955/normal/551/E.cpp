#include<bits/stdc++.h>
using namespace std;
const int N=500050,B=505,D=1000;
int n,q;
long long v[N]={},lazy[B]={};
pair<long long,int> p[N];
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&v[i]);
		p[i]={v[i],i};
	}
	for(int l=1;l<=n;l+=D)
		sort(p+l,p+min(l+D-1,n)+1);
}
void work()
{
	int type,a,b,x;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d%d",&a,&b,&x);
			for(int l=1,t=1;l<=n;l+=D,++t)
			{
				int r=min(l+D-1,n);
				if(r<a || l>b)
					continue;
				if(a<=l && r<=b)
				{
					lazy[t]+=x;
					continue;
				}
				for(int i=l;i<=r;++i)
				{
					if(a<=i && i<=b)
						v[i]+=x;
					p[i]=make_pair(v[i],i);
				}
				sort(p+l,p+r+1);
			}
		}
		else
		{
			scanf("%d",&x);
			int lp=n,rp=0;
			for(int l=1,t=1;l<=n;l+=D,++t)
			{
				int r=min(l+D-1,n);
				int p1=lower_bound(p+l,p+r+1,make_pair(x-lazy[t],0))-p;
				int p2=lower_bound(p+l,p+r+1,make_pair(x-lazy[t]+1,0))-p-1;
				if(p1<=p2)
					lp=min(lp,p[p1].second),rp=max(rp,p[p2].second);
			}
			printf("%d\n",lp>rp ? -1 : rp-lp);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}