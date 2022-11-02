#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const long long Inf=1ll<<60;
int n,m,q,a,b,c[N]={};
long long v[N]={},f[N]={};
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%I64d",&v[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	m=*max_element(c+1,c+n+1);
}
long long calc()
{
	fill(f+1,f+m+1,-Inf);
	int p1=0,p2=1;
	for(int i=1;i<=n;++i)
	{
		long long x=f[c[i]]+a*v[i];
		if(c[i]!=p1)
			x=max(x,f[p1]+b*v[i]);
		else
			x=max(x,f[p2]+b*v[i]);
		f[c[i]]=max(f[c[i]],x);
		if(c[i]!=p1)
		{
			if(f[c[i]]>=f[p1])
				p2=p1,p1=c[i];
			else
				if(f[c[i]]>=f[p2])
					p2=c[i];
		}
	}
	return *max_element(f,f+m+1);
}
void work()
{
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%I64d\n",calc());
	}
}
int main()
{
	init();
	work();
	return 0;
}