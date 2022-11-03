#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,k,last[N]={},end[N+N]={},next[N+N]={},total_edge=1;
int a[N]={},v[N]={},l[N]={},r[N]={},tot=0;
int size[N]={},f[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void dfs(int s,int f)
{
	l[s]=++tot;
	size[s]=1;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		dfs(j,s);
		size[s]+=size[j];
	}
	r[s]=tot;
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=2,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
}
void getf(int s,int fa)
{
	int s1=0,s2=0;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa)
			continue;
		getf(j,s);
		if(f[j]==size[j])
			s1+=f[j];
		else
			s2=max(s2,f[j]);
	}
	if(v[s]==0)
		f[s]=0;
	else
		f[s]=s1+s2+1;
}
bool getg(int s,int fa,int outs)
{
	int s1=0,s2j=0,s3j=0;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa)
			continue;
		if(f[j]==size[j])
			s1+=f[j];
		else
			if(f[j]>=f[s2j])
				s3j=s2j,s2j=j;
			else
				if(f[j]>f[s3j])
					s3j=j;
	}
	int s2=f[s2j];
	if(v[s])
	{
		if(outs==n-size[s])
			s1+=outs;
		else if(outs>s2)
			s2=outs,s2j=0;
		if(s1+s2+1>=k)
			return true;
	}
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa)
			continue;
		int outj=s1+s2+1;
		if(f[j]==size[j])
			outj-=f[j];
		else if(j==s2j)
			outj-=f[s2j]-f[s3j]; 
		if(v[s]==0)
			outj=0;
		if(getg(j,s,outj))
			return true;
	}
	return false;
}
bool check(int mid)
{
	for(int i=1;i<=n;++i)
		v[i]=(a[i]>=mid);/*
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<v[i]<<' ';
	cout<<endl;*/
	getf(1,0);/*
	for(int i=1;i<=n;++i)
		cout<<f[i]<<' ';
	cout<<endl;*/
	return getg(1,0,0);
}
void work()
{
	dfs(1,0);
	//check(100000);/*
	int l=1,r=1000000;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);//*/
}
int main()
{	
	init();
	work();
	return 0;
}