#pragma GCC optimize("Ofast")
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
#define db double
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int n,m,k;
vector<int>vec[maxn];
int cnt[maxn];
inline void init()
{
	FOR(i,1,n)cnt[i]=0;
	FOR(i,1,m)vec[i].clear();
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		k=gi();
		FOR(j,1,k)
		{
			int x=gi();
			vec[i].pb(x);
		}
	}
}
int pos[maxn];
inline void solve()
{
	FOR(i,1,m)pos[i]=vec[i][0];
	FOR(i,1,m)cnt[pos[i]]++;
	int maxv=0,now=0;
	FOR(i,1,n)if(cnt[i]>maxv){maxv=cnt[i],now=i;}
	if(maxv<=(m+1)/2)
	{
		puts("YES");
		FOR(i,1,m)printf("%d%c",pos[i]," \n"[i==m]);
		return ;
	}
	else
	{
		int counter=maxv;
		FOR(i,1,m)
		{
			if(pos[i]==now)
			{
				if(sz(vec[i])>=2)
				{
					pos[i]=vec[i][1];
					counter--;
				}
			}
			if(counter==(m+1)/2)break;
		}
		if(counter>(m+1)/2)puts("NO");
		else
		{
			puts("YES");
			FOR(i,1,m)printf("%d%c",pos[i]," \n"[i==m]);
			return ;
		}
	}
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}