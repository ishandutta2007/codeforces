//#pragma GCC optimize("Ofast")
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
bitset<4096>f[maxn];
int a[13][maxn];
int tot,n,k,q;
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi(),q=gi();
	FOR(i,1,k)FOR(j,1,n)a[i][j]=gi();tot=k;
}
inline void solve()
{
	FOR(i,1,k)FOR(j,0,(1<<k)-1)if(j>>(i-1)&1)f[i][j]=1;
	FOR(i,1,q)
	{
		int t=gi(),x=gi(),y=gi();
		if(t==1)f[++tot]=f[x]|f[y];
		else if(t==2)f[++tot]=f[x]&f[y];
		else
		{
			vector<pair<int,int> >vec;
			FOR(j,1,k)vec.pb(PII(a[j][y],j-1));
			sort(vec.begin(),vec.end(),greater<PII>());
			int S=0;
			FOR(i,0,k-1)
			{
				S|=(1<<vec[i].second);
				if(f[x][S]){printf("%d\n",vec[i].first);break;}
			}
		}
	}
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}