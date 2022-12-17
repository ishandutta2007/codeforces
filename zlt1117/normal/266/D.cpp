//#pragma GCC optimize("Ofast")
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
#define int ll
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
const int maxn=505;
int dis[maxn][maxn],n,m;
int u[maxn*maxn],v[maxn*maxn],w[maxn*maxn];
int rk[maxn][maxn];
inline void input()
{
	n=gi(),m=gi();
	memset(dis,0x3f,sizeof(dis));
	FOR(i,1,n)dis[i][i]=0;
	FOR(i,1,m)
	{
		u[i]=gi(),v[i]=gi(),w[i]=gi();w[i]*=2;
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=w[i];
	}
}
inline void floyd(){FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);}
inline void solve()
{
	///2*maxdis
	int p=0,minv=1e9;
	floyd();
	FOR(i,1,n)
	{
		FOR(j,1,n)rk[i][j]=j;
		sort(rk[i]+1,rk[i]+n+1,[&](int x,int y){return dis[i][x]<dis[i][y];});
	}
	FOR(i,1,n)
	{
		if(dis[i][rk[i][n]]*2<minv)
		{
			minv=dis[i][rk[i][n]]*2;
			p=i;
		}
	}
	int f1=0,f2=0,disu=-1e9,disv=-1e9,minv2=1e9;
	FOR(i,1,m)
	{
		int u=::u[i],v=::v[i],w=::w[i];
		int suf_max=dis[v][rk[u][n]];
		///not at the point,so i[1,n-1]
		for(int i=n-1;i>=1;--i)
		{
			if(dis[v][rk[u][i]]<=suf_max)continue;
			if(dis[u][rk[u][i]]+suf_max+w<minv2)
			{
				minv2=dis[u][rk[u][i]]+suf_max+w;
				f1=u,f2=v;
				disu=minv2/2-dis[u][rk[u][i]];
				disv=w-disu;
				//printf("%d %d %d %d\n",u,v,i,minv2);
			}
			suf_max=dis[v][rk[u][i]];
		}
	}
	printf("%.9lf\n",(double)min(minv,minv2)/4);
}
signed main()
{
	input();
	solve();
	return 0;
}