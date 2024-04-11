#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=205;
int n;
ll sum[maxn][maxn],cost[maxn][maxn];
ll f[maxn][maxn];
int rt[maxn][maxn],ans[maxn];
void getrt(int l,int r)
{
	if(l>=r)return;
	ans[rt[l][rt[l][r]-1]]=rt[l][r];
	ans[rt[rt[l][r]+1][r]]=rt[l][r];
	getrt(l,rt[l][r]-1);
	getrt(rt[l][r]+1,r);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		generate_n(sum[i]+1,n,read);
		partial_sum(sum[i]+1,sum[i]+n+1,sum[i]+1);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=i;k<=j;k++)
				cost[i][j]+=sum[k][i-1]+sum[k][n]-sum[k][j];
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			f[l][r]=1e18;
			for(int k=l;k<=r;k++)
			{
				ll val=f[l][k-1]+f[k+1][r]+cost[l][k-1]+cost[k+1][r];
				if(val<f[l][r]){rt[l][r]=k;f[l][r]=val;}
			}
		}
	}
	for(int i=1;i<=n;i++)rt[i][i]=i;
	getrt(1,n);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;	
}