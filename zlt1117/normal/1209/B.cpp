//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
const int maxn=105;
int n,a[maxn],b[maxn];
bool vis[1005][maxn];
int ans=0;
char s[maxn];
int now[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	scanf("%s",s+1);
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
}
inline void solve()
{
	FOR(i,1,n)
	{
		for(int j=b[i];j<=240;j+=a[i])
		{
			vis[j][i]=1;
		}
	}
	FOR(i,1,n)now[i]=s[i]-'0';
	FOR(i,0,240)
	{
		int sum=0;
		FOR(j,1,n)now[j]^=vis[i][j];
		FOR(j,1,n)sum+=now[j];
		ans=max(ans,sum);
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