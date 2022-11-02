#include<bits/stdc++.h>
using namespace std;
const int N=200020,Inf=-1;
int n,a[N]={},to[N]={},l[N]={};
long long sum[N]={};
bool in[N]={},v[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)
	{
		int x=i+a[i];
		if(x>n)
			to[i]=0,l[i]=0;
		else
			if(x-a[x]>0)
				to[i]=x-a[x],l[i]=a[x]+a[to[i]];
			else
				to[i]=0,l[i]=a[x];
	}
}
long long dfs(int s)
{
	if(s==0)
		return 0;
	if(in[s])
		return Inf;
	if(v[s])
		return sum[s];
	in[s]=true;
	v[s]=true;
	sum[s]=dfs(to[s]);
	if(sum[s]!=Inf)
		sum[s]+=l[s];
	in[s]=false;
	return sum[s];
}
void work()
{
	sum[1]=Inf;
	v[1]=true;
	for(int i=2;i<=n;++i)
		if(!v[i])
			dfs(i);
	for(int i=2;i<=n;++i)
	{
		int x=i-a[i],v=a[i]+i-1;
		if(x<=0)
			printf("%d\n",v);
		else
			if(sum[x]==Inf)
				puts("-1");
			else
				printf("%I64d\n",sum[x]+v+a[x]);
	}
}
int main()
{
	init();
	work();
	return 0;
}