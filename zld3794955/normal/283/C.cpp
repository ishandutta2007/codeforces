#include<bits/stdc++.h>
using namespace std;
const int N=303,V=100100,mod=1000000007;
#define int long long
int n,q,t,a[N]={},to[N]={},in[N]={};
int w[N]={},tot=0,s[N]={},f[V]={};
void init()
{
	cin>>n>>q>>t;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1,u,v;i<=q;++i)
	{
		cin>>u>>v;
		to[u]=v;
		in[v]=true;
	}
}
void dfs(int now)
{
	s[now]+=a[now];
	w[++tot]=s[now];
	if(to[now])
	{
		--q;
		s[to[now]]=s[now];
		t-=s[now];
		dfs(to[now]);
	}
}
void work()
{
	for(int i=1;i<=n;++i)
		if(!in[i])
			dfs(i);
	if(q || t<0)
	{
		puts("0");
		return;
	}
	f[0]=1;
	for(int i=1;i<=tot;++i)
		for(int j=w[i];j<=t;++j)
			f[j]=(f[j]+f[j-w[i]])%mod;
	cout<<f[t]<<endl;
}
#undef int
int main()
{	
	init();
	work();
	return 0;
}