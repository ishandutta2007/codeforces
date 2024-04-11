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
char s[10];
int len,n;
inline void init()
{
	
}
inline void NO()
{
	printf("NO\n");
}
inline void YES()
{
	printf("YES\n");
}
inline void input()
{
	n=gi();
}
inline void solve()
{
	int nowx=0,nowy=0;
	FOR(i,1,n)
	{
		scanf("%d%s",&len,s+1);
		if(nowx==0&&s[1]!='S')return NO();
		if(nowx==20000&&s[1]!='N')return NO();
		if(s[1]=='S')nowx+=len;
		if(s[1]=='N')nowx-=len;
		if(s[1]=='W')nowy+=len;
		if(s[1]=='E')nowy-=len;
		if(nowx>20000||nowx<0)return NO();
	}
	if(nowx==0)return YES();
	return NO();
}
int main()
{
	init();
	input();
	solve();
	return 0;
}