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
const int maxn=105;
bool vis[maxn][maxn];
int a[maxn];
int cnt1=0,cnt2=0,n;
///grader
int e[maxn][maxn];
///grader
inline int q1(int a,int b)
{
	cnt1++;assert(cnt1<=9*n);
	assert(a>=0&&a<=n-1&&b>=0&&b<=n-1&&a!=b);
	///grader
//	return e[a][b];
	///grader
	printf("1 %d %d\n",a,b);
	fflush(stdout);
	int ret=gi();return ret;
}
inline int q2(int a,vector<int>&vec)
{
	cnt2++;assert(cnt2<=2*n);
	assert(a>=0&&a<=n-1&&sz(vec)>=0&&sz(vec)<=n-1);
	for(int x:vec)assert(x!=a);
	///grader
//	for(int x:vec)if(e[a][x])return 1;
//	return 0;
	///grader
	printf("2 %d %d ",a,sz(vec));
	for(int x:vec)printf("%d ",x);printf("\n");
	fflush(stdout);
	int ret=gi();return ret;
}
inline void answer()
{
	puts("3");
	FOR(i,0,n-1)
	{
		FOR(j,0,n-1)printf("%d",vis[i][j]);
		puts("");
	}
	fflush(stdout);
	int ret=gi();assert(ret!=-1);
}
inline void init()
{
	cnt1=cnt2=0;
	memset(vis,1,sizeof(vis));
	memset(a,0,sizeof(a));
}
inline void input()
{
	n=gi();
	///grader
//	FOR(i,0,n-1)
//	{
//		string s;
//		cin>>s;
//		FOR(j,0,n-1)e[i][j]=s[j]-'0';
//	}
	///grader
	FOR(i,0,n-1)a[i]=i;
	stable_sort(a,a+n,[&](int a,int b){return q1(a,b);});
}
inline void solve()
{
	int last=n-1;
	for(int i=n-1;i>=0;--i)
	{
		while(last>=0)
		{
			if(i==last){last--;continue;}
			vector<int>now;
			FOR(j,0,last)now.pb(a[j]);
			if(q2(a[i],now))last--;
			else break;
		}
		if(last==i-1)FOR(j,0,i-1)FOR(k,i,n-1)vis[a[k]][a[j]]=0;
	}	
	answer();
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