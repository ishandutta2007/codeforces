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
const int maxn=2e5+5;
int T;
char s[maxn];
int a[maxn],b[maxn],c[maxn],n;
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	scanf("%s",s+1);
	FOR(i,1,n)a[i]=s[i]-'0',b[i]=a[i],vis[i]=0;
	sort(b+1,b+n+1);
}
inline void solve()
{
	int tot=0;
	FOR(i,1,n)
	{
		if(a[i]==b[tot+1])
		{
			c[++tot]=a[i];
			vis[i]=1;
		}
	}
	FOR(i,1,n)if(!vis[i])c[++tot]=a[i];
	FOR(i,1,n-1)if(c[i]>c[i+1]){printf("-\n");return ;}
	FOR(i,1,n)printf(vis[i]?"1":"2");
	printf("\n");
}
int main()
{
	T=gi();
	while(T--)
	{	
		init();
		input();
		solve();
	}
	return 0;
}
///