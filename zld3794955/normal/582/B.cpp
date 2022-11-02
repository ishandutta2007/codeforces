#include<bits/stdc++.h>
using namespace std;
const int N=103,Inf=1<<30;
int n,m,T,a[N]={},v[N]={},f[N][N]={},ans[N][N]={},tmp[N][N]={};
int main()
{	
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	copy(a+1,a+n+1,v+1);
	sort(v+1,v+n+1);
	m=unique(v+1,v+n+1)-v-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(v+1,v+m+1,a[i])-v;
	for(int i=1;i<=n;++i)
	{
		int g[N]={};
		g[i]=1;
		for(int j=i+1;j<=n;++j)
		{
			g[j]=-Inf;
			for(int k=i;k<j;++k)
				if(a[j]>=a[k])
					g[j]=max(g[j],g[k]+1);
		}
		for(int j=i;j<=n;++j)
			f[a[i]][a[j]]=max(f[a[i]][a[j]],g[j]);
	}
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			f[i][j]=max(f[i][j],f[i][j-1]);
	while(T)
	{
		if(T&1)
		{
			for(int i=1;i<=m;++i)
				for(int j=1;j<=m;++j)
					tmp[i][j]=0;
			for(int i=1;i<=m;++i)
				for(int j=i;j<=m;++j)
					for(int k=j;k<=m;++k)
						tmp[i][k]=max(tmp[i][k],ans[i][j]+f[j][k]);
			for(int i=1;i<=m;++i)
				for(int j=1;j<=m;++j)
					ans[i][j]=tmp[i][j];
		}
		T>>=1;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j)
				tmp[i][j]=0;
		for(int i=1;i<=m;++i)
			for(int j=i;j<=m;++j)
				for(int k=j;k<=m;++k)
					tmp[i][k]=max(tmp[i][k],f[i][j]+f[j][k]);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j)
				f[i][j]=tmp[i][j];
	}
	int len=0;
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)
			len=max(len,ans[i][j]);
	cout<<len<<endl;
	return 0;
}