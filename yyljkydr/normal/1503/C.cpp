#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

struct D{
	int a,c;
	int id;
}p[N];

bool operator <(const D &a,const D &b)
{
	return a.a<b.a;
}

int main()
{
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].c),p[i].id=i,ans+=p[i].c;
	sort(p+1,p+n+1);
	int last=1,px=1;
	int mst=0;
	while(1)
	{
		int mx=0;
		for(int i=last;i<=px;i++)
			mx=max(mx,p[i].a+p[i].c);
		mst=max(mst,mx);
		D tmp;
		tmp.a=mx;
		int r=upper_bound(p+1,p+n+1,tmp)-p-1;
		if(r<=px)
		{
			ans+=p[px+1].a-mst;
			px=px+1;
			last=px;
		}
		else
		{
			last=px+1;
			px=r;
		}
		if(px==n)
			break;
	}
	printf("%lld\n",ans);
}