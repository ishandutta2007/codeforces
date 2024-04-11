#include<bits/stdc++.h>
using namespace std;
const int N=2020,mod=1000000007;
int n,m,t=0,a[N]={},vis[N]={};
int *f[N]={},*g,*h,arr[N][N<<2]={};
vector<int> e[N];
long long ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<=m;++i)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(auto x:e[1])
		if(!vis[x])
		{
			int l=1,now=x,last=1,tmp;
			vis[now]=true;
			while(now!=1)
			{
				tmp=last;
				last=now;
				now=e[now][e[now][0]==tmp];
				vis[now]=true;
				++l;
			}
			a[++t]=l;
		}
	/*
	for(int i=1;i<=t;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	*/
	for(int i=0;i<=t;++i)
		f[i]=arr[i]+m;
	f[0][0]=1;
	for(int i=1;i<=t;++i)
		for(int v=-m;v<=m;++v)
		{
			if(v+a[i]<=m)
				f[i][v]=(f[i][v]+f[i-1][v+a[i]])%mod;
			if(v-a[i]>=-m)
				f[i][v]=(f[i][v]+f[i-1][v-a[i]])%mod;
			f[i][v]=(f[i][v]+f[i-1][v])%mod;
		}
		/*
	for(int v=-m;v<=m;++v)
		cout<<f[t][v]<<' ';
	cout<<endl;*/
	g=arr[t+1]+m;
	h=arr[t+2]+m;
	for(int i=1;i<=t;++i)
	{
		copy(f[t]-m,f[t]+m+1,g-m);
		fill(h-m,h+m+1,0);
		for(int v=-m;v<=m;++v)
		{
			g[v+a[i]]=(g[v+a[i]]+mod-g[v])%mod;
			g[v+a[i]+a[i]]=(g[v+a[i]+a[i]]+mod-g[v])%mod;
			h[v+a[i]]=g[v];
			g[v]=0;
		}/*
		for(int j=-m;j<=m;++j)
			cout<<h[j]<<' ';
		cout<<endl;*/
		for(int v=-a[i]+2;v<=a[i]-2;++v)
			ans=(ans+h[v]*2%mod)%mod;
		//cout<<"i="<<i<<" "<<ans<<endl;
	}
	//cout<<ans<<endl;
	memset(arr,0,sizeof(arr));
	f[0][0]=1;
	for(int i=1;i<=t;++i)
		for(int v=-m;v<=m;++v)
		{
			if(v+a[i]<=m)
				f[i][v]=(f[i][v]+f[i-1][v+a[i]])%mod;
			if(v-a[i]>=-m)
				f[i][v]=(f[i][v]+f[i-1][v-a[i]])%mod;
		}
	g=arr[t+1]+m;
	h=arr[t+2]+m;
	for(int i=1;i<=t;++i)
	{
		copy(f[t]-m,f[t]+m+1,g-m);
		fill(h-m,h+m+1,0);
		for(int v=-m;v<=m;++v)
		{
			g[v+a[i]+a[i]]=(g[v+a[i]+a[i]]+mod-g[v])%mod;
			h[v+a[i]]=g[v];
			g[v]=0;
		}
		ans=(ans+h[a[i]-1]*2ll+h[1-a[i]]*2ll)%mod;
		//cout<<"i="<<i<<" "<<ans<<endl;
	}
	ans=(ans+f[t][0])%mod;
	cout<<ans<<endl;
}