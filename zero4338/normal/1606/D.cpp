#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=5e5+5;
const int inf=1e9;
int n,m;
vector<vector<int>>a,premi,premx,sufmi,sufmx;
int id[maxn],lpremx[maxn],lsufmi[maxn],rpremi[maxn],rsufmx[maxn];
char col[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		a.clear();premi.clear();premx.clear();sufmi.clear();sufmx.clear();
		a.resize(n+5,vector<int>(m+5));
		premi.resize(n+5,vector<int>(m+5));sufmi.resize(n+5,vector<int>(m+5));
		premx.resize(n+5,vector<int>(m+5));sufmx.resize(n+5,vector<int>(m+5));
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
		for(int i=1;i<=n;i++)
		{
			premi[i][0]=inf;premx[i][0]=-inf;
			for(int j=1;j<=m;j++)
			{
				premi[i][j]=min(premi[i][j-1],a[i][j]);
				premx[i][j]=max(premx[i][j-1],a[i][j]);
			}
			sufmi[i][m+1]=inf;sufmx[i][m+1]=-inf;
			for(int j=m;j>=1;j--)
			{
				sufmi[i][j]=min(sufmi[i][j+1],a[i][j]);
				sufmx[i][j]=max(sufmx[i][j+1],a[i][j]);
			}
		}
		for(int i=1;i<=n;i++)id[i]=i;sort(id+1,id+n+1,[](int &i,int &j){return a[i][1]<a[j][1];});
		bool flag=0;
		for(int i=1;i<m;i++)
		{
			lpremx[0]=-inf;
			rpremi[0]=inf;
			for(int j=1;j<=n;j++)
			{
				lpremx[j]=max(lpremx[j-1],premx[id[j]][i]);
				rpremi[j]=min(rpremi[j-1],sufmi[id[j]][i+1]);
			}
			lsufmi[n+1]=inf;
			rsufmx[n+1]=-inf;
			for(int j=n;j>=1;j--)
			{
				lsufmi[j]=min(lsufmi[j+1],premi[id[j]][i]);
				rsufmx[j]=max(rsufmx[j+1],sufmx[id[j]][i+1]);
			}
			for(int j=1;j<n;j++)
			{
				if(lpremx[j]<lsufmi[j+1]&&rpremi[j]>rsufmx[j+1])
				{
					puts("YES");
					for(int k=1;k<=j;k++)col[id[k]]='B';
					for(int k=j+1;k<=n;k++)col[id[k]]='R';
					for(int k=1;k<=n;k++)printf("%c",col[k]);printf(" %d\n",i);
					flag=1;break;
				}
			}
			if(flag)break;
		}
		if(!flag)puts("NO");
	}
}