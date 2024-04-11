#include<bits/stdc++.h>
using namespace std;
const int N=200020,V=500050;
int n,q,a[N]={},t[V]={};
int prime[V]={},ptot=0,minp[V]={};
long long ans=0;
bool del[V]={},in[N]={};
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	const int v=500000;
	for(int i=2;i<=v;++i)
	{
		if(!del[i])
			prime[++ptot]=i,minp[i]=i;
		for(int j=1; i*prime[j]<=v; ++j)
		{
			del[i*prime[j]]=true;
			minp[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
void add(int v,int c)
{
	int a[10]={},tot=0;
	while(minp[v])
	{
		if(a[tot]!=minp[v])
			a[++tot]=minp[v];
		v/=minp[v];
	}
	for(int s=(1<<tot)-1;s>=0;--s)
	{
		int k=1,tmp=1;
		for(int i=0;i<tot;++i)
			if(s&(1<<i))
			{
				k=-k;
				tmp*=a[i+1];
			}
		if(c==1)
			ans+=t[tmp]*k*c,t[tmp]+=c;
		else
			t[tmp]+=c,ans+=t[tmp]*k*c;
	}
}
void work()
{
	for(int i=1,x=0;i<=q;++i)
	{
		scanf("%d",&x);
		if(in[x])
			add(a[x],-1);
		else
			add(a[x],1);
		in[x]=!in[x];
		printf("%I64d\n",ans);
	}
}
int main()
{
	init();
	work();
	return 0;
}