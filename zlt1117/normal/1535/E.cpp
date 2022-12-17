#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
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
const int maxn=3e5+5;
int Q,a[maxn],c[maxn];
int fa[maxn][20],Log[maxn],dep[maxn];
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
inline int get(int x)
{
	for(int i=Log[dep[x]];i>=0;--i)
	{
		if(a[fa[x][i]]!=0)x=fa[x][i];
	}
	return x;
}
inline void query(int v,int w)
{
	ll ans=0,cnt=0;
	while(1)
	{
		int now=get(v);
		if(now==v&&a[v]==0)break;
		if(a[now]>w)
		{
			a[now]-=w;cnt+=w;
			ans+=1ll*w*c[now];
			printf("%lld %lld\n",cnt,ans);
			return ;
		}
		else
		{
			ans+=1ll*c[now]*a[now];cnt+=a[now];w-=a[now];
			a[now]=0;
		}
	}
	printf("%lld %lld\n",cnt,ans);
}
inline void input()
{
	Q=gi();a[1]=gi(),c[1]=gi(),dep[1]=1;
}
inline void solve()
{
	FOR(i,1,Q)
	{
		int typ=gi();
		if(typ==1)
		{
			fa[i+1][0]=gi();fa[i+1][0]++;
			a[i+1]=gi(),c[i+1]=gi();
			dep[i+1]=dep[fa[i+1][0]]+1;
			FOR(j,1,Log[dep[i+1]])fa[i+1][j]=fa[fa[i+1][j-1]][j-1];
		}
		else
		{
			int v=gi(),w=gi();v++;
			query(v,w);
			fflush(stdout);
		}
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}