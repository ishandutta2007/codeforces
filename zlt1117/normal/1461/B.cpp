#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=505;
char s[maxn][maxn];
int n,m;
int lef[maxn][maxn],rig[maxn][maxn];
inline void init()
{
	FOR(i,0,n+1)FOR(j,0,m+1)lef[i][j]=rig[i][j]=0;
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)scanf("%s",s[i]+1);
}
inline void solve()
{
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			lef[i][j]=rig[i][j]=j;
			if(s[i][j-1]=='*')lef[i][j]=lef[i][j-1];
		}
	}
	FOR(i,1,n)
	{
		for(int j=m;j>=1;--j)
		{
			if(s[i][j+1]=='*')rig[i][j]=rig[i][j+1];
		}
	}
	int ans=0;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			///from [i,j]
			FOR(k,0,n)
			{
				if(j-k>=1&&j+k<=m&&i+k<=n&&s[i+k][j]=='*')
				{
					if(lef[i+k][j]<=j-k&&rig[i+k][j]>=j+k)
					{
						ans++;
					}
					else break;
				}
				else break;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}