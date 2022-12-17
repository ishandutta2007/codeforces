#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
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
int x;
inline void init()
{

}
inline void input()
{
	x=gi();
}
inline void solve()
{
	int sum=0,now=0;
	for(int i=1;;++i)
	{
		now=i;
		sum+=i;
		if(sum>=x)break;
	}
	if(sum==x)printf("%d\n",now);
	else if(sum==x+1)printf("%d\n",now+1);
	else printf("%d\n",now);
}
int main()
{
	int T;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}