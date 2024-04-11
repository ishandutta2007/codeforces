#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;

int n,m,num[N],g,ans;
bool vis[N];

inline int gcd(int u,int v)
{
	if(!u||!v) return u+v;
	for(;u!=v&&u&&v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}

int main()
{
	int i,j,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		num[i]%=m;
		g=gcd(g,num[i]);
	}
	t=g;
//	cout<<g;return 0;
	for(;!vis[g];g=(g+t)%m)
	{
		vis[g]=1;
		ans++;
	}
	cout<<ans<<endl;
	for(i=0;i<m;i++)
	{
		if(vis[i]) printf("%d ",i);
	}
}