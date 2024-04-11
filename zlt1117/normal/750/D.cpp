//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int dr[8]={0,-1,-1,-1,0,1,1,1};
int dc[8]={1,1,0,-1,-1,-1,0,1};
const int maxn=505;
bool vis[maxn][maxn][9][31],temp[maxn][maxn];
int nowx=250,nowy=250;
int ans,t[maxn],n;
struct node
{
	int x,y,times,dir;
};
queue<node>q;
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)t[i]=gi();
	q.push({nowx,nowy,1,2});
	while(!q.empty())
	{
		node x=q.front(),now=x;
		q.pop();
		if(vis[x.x][x.y][x.times][x.dir]||x.times>n)continue;
		vis[x.x][x.y][x.times][x.dir]=1;
		FOR(i,1,t[x.times])
		{
			now.x+=dr[x.dir];
			now.y+=dc[x.dir];
			temp[now.x][now.y]=1;
		}
		q.push({now.x,now.y,now.times+1,(now.dir+7)%8});
		q.push({now.x,now.y,now.times+1,(now.dir+1)%8});
	}
}
inline void solve()
{
	FOR(i,0,500)
	{
		FOR(j,0,500)
		{
			ans+=temp[i][j];
		}
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}