#include<bits/stdc++.h>
using namespace std;
const int N=200200,Q=200200,V=1001000,mod=1000000007;
inline long long power(long long x,long long y)
{
	long long t=1;
	for(; y; y>>=1,x=x*x%mod)
		if(y&1) t=t*x%mod;
	return t;
}
struct query
{
	int l,r,num;
}p[Q]={};
int n,q,a[N]={},pri[V]={},minp[V]={},b[V]={};
long long t[N]={},ans[Q]={};
inline void multi(int pos,long long v)
{
	for(int i=pos;i<=n;i+=i&(-i))
		t[i]=t[i]*v%mod;
}
inline long long product(int pos)
{
	long long v=1;
	for(int i=pos;i;i-=i&(-i))
		v=v*t[i]%mod;
	return v;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=0;i<=n;++i)
		t[i]=1;
	int v=*max_element(a+1,a+n+1);
	for(int i=2,tot=0;i<=v;++i)
	{
		if(!minp[i])
			pri[++tot]=i,minp[i]=i;
		for(int j=1;pri[j]*i<=v;++j)
		{
			minp[i*pri[j]]=pri[j];
			if(i%pri[j]==0)
				break;
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].num=i;
	}
	sort(p+1,p+q+1,[](const query &q1,const query &q2){return q1.r<q2.r;});
}
void change(int i)
{
	int x=a[i];
	while(x!=1)
	{
		int now=minp[x];
		if(b[now])
		{
			multi(b[now],power(now-1,mod-2));
			multi(b[now],now);
		}
		b[now]=i;
		multi(i,now-1);
		x/=now;
	}
}
void work()
{
	for(int i=1,now=1;i<=q;++i)
	{
		while(now<=p[i].r)
			change(now++);
			
		ans[p[i].num]=product(p[i].r)*power(product(p[i].l-1),mod-2)%mod;
	}
	for(int i=1;i<=q;++i)
		printf("%I64d\n",ans[i]);
}
int main()
{	
	init();
	work();
	return 0;
}