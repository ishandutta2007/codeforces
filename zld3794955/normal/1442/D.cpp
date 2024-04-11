#include<bits/stdc++.h>
using namespace std;
const int N=3030,D=15;
long long f[D][N]={};
long long ans=0;
int n,k,v[N]={};
long long w[N][N]={};
void merge(int d,int l,int r)
{
	copy(f[d-1]+1,f[d-1]+k+1,f[d]+1);
	for(int i=l;i<=r;++i)
	{
		int V=min(v[i],k);
		for(int j=k;j>=V;--j)
			f[d][j]=max(f[d][j],f[d][j-V]+w[i][V]);
	}
}
void dp(int d,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=min(v[l],k);++i)
			ans=max(ans,f[d-1][k-i]+w[l][i]);
		return;
	}
	int mid=(l+r)>>1;
	merge(d,l,mid);
	dp(d+1,mid+1,r);
	merge(d,mid+1,r);
	dp(d+1,l,mid);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",v+i);
		int x;
		for(int j=1;j<=v[i];++j)
		{
			scanf("%d",&x);
			if(j<=k)
				w[i][j]=w[i][j-1]+x;
		}
		v[i]=min(v[i],k);
	}
	dp(1,1,n);
	cout<<ans<<endl;
}