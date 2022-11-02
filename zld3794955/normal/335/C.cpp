#include<bits/stdc++.h>
using namespace std;
const int N=110;
int r,n,a[N][3]={},f[N]={},g[N]={},h[N]={};
void init()
{
	cin>>n>>r;
	for(int i=1,x=0,y=0;i<=r;++i)
	{
		cin>>x>>y;
		a[x][y]=true;
	}
	f[1]=0,g[1]=0;
	f[2]=0,g[2]=1;
	for(int i=3;i<=n;++i)
	{
		bool v1[N]={},v2[N]={};
		for(int j=2;j<i;++j)
			v1[f[j]^g[i-j]]=true;
		for(int j=2;j<i-1;++j)
			v2[f[j]^f[i-j]]=true;
		for(int j=1;j<i;++j)
			v2[g[j]^g[i-j]]=true;
		for(int j=0;j<=n;++j)
			if(!v1[j])
			{
				f[i]=j;
				break;
			}
		for(int j=0;j<=n;++j)
			if(!v2[j])
			{
				g[i]=j;
				break;
			}
	}
	h[1]=0;
	for(int i=2;i<=n;++i)
	{
		bool v[N]={};
		for(int j=1;j<i;++j)
			v[h[j]^g[i-j]]=true;
		for(int j=1;j<i-1;++j)
			v[h[j]^f[i-j]]=true;
		for(int j=0;j<=n;++j)
			if(!v[j])
			{
				h[i]=j;
				break;
			}
	}
	//for(int i=1;i<=n;++i)
	//	cout<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
}
void work() 
{
	int last=0,p=0,s=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i][1])
		{
			if(last)
				s^=p==1 ? g[i-last] : f[i-last];
			else
				s^=h[i];
			last=i,p=1;
		}
		if(a[i][2])
		{
			if(last)
				s^=p==2 ? g[i-last] : f[i-last];
			else
				s^=h[i];
			last=i,p=2;
		}
	}
	if(last==0)
	{
		bool v[N]={};
		for(int i=1;i<=n;++i)
			v[h[i]^h[n-i+1]]=true;
		for(int i=0;i<=n;++i)
			if(!v[i])
			{
				s=i;
				break;
			}
	}
	else
		s^=h[n+1-last];
	puts(s ? "WIN" : "LOSE");
}
int main()
{
	init();
	work();
	return 0;
}