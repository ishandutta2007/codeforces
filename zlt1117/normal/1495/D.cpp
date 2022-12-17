///Chinese new year,I love bfs
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
const int maxn=405,maxm=605,mod=998244353;
int n,m;
int dis[maxn][maxn],cnt[maxn][maxn];
vector<int>e[maxn];
inline void input()
{
	n=gi(),m=gi();
	memset(dis,0x3f,sizeof(dis));
	FOR(i,1,n)dis[i][i]=0;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
		dis[u][v]=dis[v][u]=1;
	}
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
inline void bfs(int x)
{
	queue<int>q;q.push(x);cnt[x][x]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])
		{
			if(!cnt[x][v])
			{
				cnt[x][v]+=cnt[x][u];
				q.push(v);
			}
			else if(dis[x][v]==dis[x][u]+1)cnt[x][v]+=cnt[x][u];
		}
	}
}
inline int count(int x,int y)
{
	int ans=1;
	FOR(i,1,n)
	{
		if(dis[x][i]+dis[i][y]==dis[x][y])continue;///in this path
		int sum=0;
		///find his father
		for(int v:e[i])if(dis[x][v]+1==dis[x][i]&&dis[y][v]+1==dis[y][i])sum++;
		ans=1ll*ans*sum%mod;
	}
	return ans;
}
inline void solve()
{
	FOR(i,1,n)bfs(i);
	FOR(i,1,n)FOR(j,1,n)
	{
		if(cnt[i][j]>=2)printf("0 ");
		else printf("%d ",count(i,j));
		if(j==n)puts("");
	}
}
int main()
{
	input();
	solve();
	return 0;
}