#include<bits/stdc++.h>
using namespace std;
const int N=55,One=50,mod=1000000007,Inf=1<<30;
int n,k,t[3],C[N][N]={},d[N][N][2]={},f[N][N][N<<2]={},ans1;
bool v[N][N][N<<2]={};
void init()
{
	scanf("%d%d",&n,&k);
	k/=One;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x/One];
	}
	for(int i=0;i<=n;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
void spfa()
{
	for(int x=0;x<=t[1];++x)
		for(int y=0;y<=t[2];++y)
			d[x][y][0]=d[x][y][1]=Inf;
	d[0][0][1]=0;
	for(int T=0;T<=2500;++T)
		for(int x=0;x<=t[1];++x)
			for(int y=0;y<=t[2];++y)
			{
				if(x!=t[1])
					d[x][y][1]=min(d[x][y][1],d[x+1][y][0]+1);
				if(y!=t[2] && k>=2)
					d[x][y][1]=min(d[x][y][1],d[x][y+1][0]+1);
				for(int i=0;i<=x;++i)
					for(int j=0;j<=y;++j)
						if(i+j && i+j+j<=k)
							d[x][y][0]=min(d[x][y][0],d[x-i][y-j][1]+1);
			}
}
int dfs2(int x,int y,int d)
{
	if(d==ans1)
		return f[x][y][d];
	if(v[x][y][d])
		return f[x][y][d];
	v[x][y][d]=true;
	f[x][y][d]=0;
	if(d%2)
	{
		for(int i=0;i<=t[1]-x;++i)
			for(int j=0;j<=t[2]-y;++j)
				if(i+j && i+j+j<=k)
					(f[x][y][d]+=dfs2(x+i,y+j,d+1)*1ll*C[t[1]-x][i]%mod*C[t[2]-y][j]%mod)%=mod;
	}
	else
	{
		for(int i=0;i<=x;++i)
			for(int j=0;j<=y;++j)
				if(i+j && i+j+j<=k)
					(f[x][y][d]+=dfs2(x-i,y-j,d+1)*1ll*C[x][i]%mod*C[y][j]%mod)%=mod;
	}
	return f[x][y][d];
}
void work()
{
	spfa();
	if(d[t[1]][t[2]][0]==Inf)
	{
		puts("-1\n0");
		return;
	}
	ans1=d[t[1]][t[2]][0];
	f[0][0][ans1]=1;
	dfs2(t[1],t[2],0);
	printf("%d\n%d\n",ans1,f[t[1]][t[2]][0]);
}
int main()
{	
	init();
	work();
	return 0;
}